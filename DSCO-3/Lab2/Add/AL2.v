module AL2(x1, x2, x3, f);
    input x1, x2, x3;
    output f;
    not(Nx1, x1);
    not(Nx2, x2);
    not(Nx3, x3);
    and(X1X3, Nx1, x3);
    and(X1X2, x1, Nx2);
    and(X2X3, x2, Nx3);
    or(f, X1X2, X1X3, X2X3);
endmodule