module fourAS(a,b,k,s,c);
input [3:0]a;input [3:0]b;
input k;
output [3:0]s;
output c;
wire c1, c2, c3;

FullAdder fa1(a[0],b[0]^k,k,s[0],c1);
FullAdder fa2(a[1],b[1]^k,c1,s[1],c2);
FullAdder fa3(a[2],b[2]^k,c2,s[2],c3);
FullAdder fa4(a[3],b[3]^k,c3,s[3],c);
endmodule

module FullAdder(x, y, z, s, c);
input x, y ,z;
output s, c;
assign s=x^y^z;
assign c=x&y|y&z|x&z;
endmodule