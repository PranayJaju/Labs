module Q2i(a, b, c, d, f, g);
    input a, b, c, d;
    output f, g;
    nand(l, a, b);
    nor(g, b, c, d);
    xor(f, c, d, l);
endmodule    