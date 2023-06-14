module q2ii(x, y, z, F);
    input x, y, z;
    output F;
    nand(Z, z, z);
    nand(XZ, Z, x);
    nand(Y, y, y);
    nand(F, XZ, Y);
endmodule