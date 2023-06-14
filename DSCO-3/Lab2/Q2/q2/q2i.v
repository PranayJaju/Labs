module q2i(x, y, z, F);
    input x, y, z;
    output F;
    nor(X, x, x);
    nor(XZ, X, z);
    nor(f, XZ, y);
    nor(F, f, f);
endmodule