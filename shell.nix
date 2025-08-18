{
  pkgs ? import <nixpkgs> { },
}:

pkgs.mkShell {
  buildInputs = with pkgs; [
    clang # C++ compiler
    cmake # CMake build system
    cmake-format # CMake format tool
    nixfmt # Nix formatter
    nixfmt-tree # Nix formatter tree
    just # Just runner
  ];

  # Shell hook to set up environment
  shellHook = "";
}
