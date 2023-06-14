module Q2ii(a, b, c, d, f, g);
    input a, b, c, d;
    output f, g;
    assign f=(~(a&b)^d^c);
    assign g=~(b|c|d);
endmodule    