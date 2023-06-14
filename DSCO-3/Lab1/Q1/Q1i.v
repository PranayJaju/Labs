module Q1i(a, b, c, d, f);
    input a, b, c, d;
    output f;
    and(l, a, b);
    or(m, l, c);
    not(n, m);
    and(o, d, n);
    or(p, d, m);
    and(f, o, p);
endmodule    