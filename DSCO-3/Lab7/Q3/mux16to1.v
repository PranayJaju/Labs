module mux16to1(w, s, f);
input[15:0]w;
input[3:0]s;
output f;
wire [1:0]o;

mux8to1 s1(w[7:0], s[2:0], o[0]);
mux8to1 s2(w[15:8], s[2:0], o[1]);
mux2to1 s5(o[1:0], s[3], f);
endmodule

module mux8to1(w,s,f);
input [7:0]w;
input [2:0]s;
output reg f;
always@(w or s)
begin
case(s)
0:f=w[0];
1:f=w[1];
2:f=w[2];
3:f=w[3];
4:f=w[4];
5:f=w[5];
6:f=w[6];
7:f=w[7];
endcase
end
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