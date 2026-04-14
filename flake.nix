{
  description = "ASTRA unilib";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";

    treefmt = {
      url = "github:numtide/treefmt-nix";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  outputs =
    {
      self,
      nixpkgs,
      flake-utils,
      treefmt,
    }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = import nixpkgs { inherit system; };
        python = pkgs.python313;

        unilib = python.pkgs.buildPythonPackage {
          pname = "unilib";
          version = "0.0.0";
          pyproject = true;

          src = pkgs.lib.cleanSource ./.;

          build-system = [
            python.pkgs.scikit-build-core
            python.pkgs.pybind11
          ];

          nativeBuildInputs = [
            pkgs.cmake
            pkgs.ninja
          ];

          dontUseCmakeConfigure = true;

          pythonImportsCheck = [ "unilib" ];
        };

        # python with unilib installed for testing
        python-with-unilib = python.withPackages (ps: [ unilib ]);
      in
      {
        packages = {
          default = unilib;
          inherit unilib;
          python = python-with-unilib;
        };

        apps.default = {
          type = "app";
          program = "${python-with-unilib}/bin/python";
        };

        devShells.default = pkgs.mkShell {
          name = "unilib development shell";
          packages = [
            pkgs.cmake
            pkgs.ninja
            (python.withPackages (
              p: with p; [
                pybind11
                scikit-build-core
                pip
              ]
            ))
          ];
        };

        formatter = (treefmt.lib.evalModule pkgs ./treefmt.nix).config.build.wrapper;
      }
    );
}
