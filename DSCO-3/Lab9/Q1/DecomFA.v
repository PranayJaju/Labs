module DecomFA(x,y,z,s,c);
input x,y,z;
output s,c;
HalfAdder h1(x,y,st,ct1);
HalfAdder h2(st,z, s, ct2);
assign c=ct1|ct2;
endmodule


module HalfAdder(x, y, s, c);
input x, y;
output s, c;
assign s=x^y;
assign c=x&y;
endmodule