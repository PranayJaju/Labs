module FullAdder(x, y, z, s, c);
input x, y ,z;
output s, c;
s=x^y^z;
assign c=x&y|y&z|x&z;
endmodule