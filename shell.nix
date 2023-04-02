{ pkgs ? import <unstable> {}  } : with pkgs; pkgs.mkShell  {
  buildInputs = [
    stdenv
    pkg-config
    (ncurses.override { stdenv = stdenv; })
  ];

}
