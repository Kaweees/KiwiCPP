{ pkgs ? import <nixpkgs> { } }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    cmake # CMake build system
    cmake-format # CMake format tool
    nixfmt-classic # Nix formatter
    clang # C++ compiler
    just # Just runner
  ];

  # Shell hook to set up environment
  shellHook = ''
    export CMAKE_CXX_FLAGS="-std=c++14"
  '';
}
