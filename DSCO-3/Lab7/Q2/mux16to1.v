module mux16to1(w, s, f);
input[15:0]w;
input[3:0]s;
output f;
wire [3:0]o;

mux4to1 s1(w[3:0], s[1:0], o[0]);
mux4to1 s2(w[7:4], s[1:0], o[1]);
mux4to1 s3(w[11:8], s[1:0], o[2]);
mux4to1 s4(w[15:12], s[1:0], o[3]);
mux4to1 s5(o[3:0], s[3:2], f);

endmodule

module mux4to1(w, s, f);
    input [3:0]w;
    input [1:0]s;
    output reg f;
    always@(w or s)
    f=s[1]?(s[0]?w[3]:w[2]):(s[0]?w[1]:w[0]);
endmodule