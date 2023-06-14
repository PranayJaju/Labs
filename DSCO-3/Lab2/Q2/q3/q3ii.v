module q3ii(x1, x2, x3, f);
    input x1, x2, x3;
    output f;
    nand(X1, x1, x1);
    nand(X2, x2, x2);
    nand(X1X2, X1, X2);
    nand(X1X3, x1, x3);
    nand(F, X1X3, X1X2);
    nand(f, F, F);
endmodule