# This shell does not work from any appimage !
# This might make your compilation failed !!!!
# Be careful ! Do not waste your time !


{
    pkgs ? import <nixpkgs> {},
    extraPkgs ? []
}:
pkgs.mkShell {
    buildInputs = with pkgs; [
        gcc-arm-embedded
        cmake
        gnumake
        gdb
    ];
    packages = with pkgs; [
        openocd
        (python3.withPackages (p: with p; [
            pip
            psutil
            virtualenv
            pyserial
        ]))
    ];
    inputsFrom = with pkgs; [
        gcc-arm-embedded
    ];

    shellHook = ''
        export OBJCOPY=arm-none-eabi-objcopy
  '';
}
