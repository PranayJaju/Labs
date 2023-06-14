module mux4to1(w, s, f);
input [3:0]w;
input [1:0]s;
output f;
wire [1:0]a;

mux2to1 s1(w[1:0], s[0], a[0]);
mux2to1 s2(w[3:2], s[0], a[1]);
mux2to1 s3(a[1:0], s[1], f);

endmodule

module mux2to1(w, s, f);
    input [1:0]w;
    input s;
    output reg f;
    always @(w or s)
    begin
        if(s==0)
        f=w[0];
        else 
        f=w[1];
        end
endmodule