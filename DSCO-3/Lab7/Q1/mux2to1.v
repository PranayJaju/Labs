module mux2to1(w, s, f);
    input [1:0]w;
    input s;
    output reg f;
    always @(w or s)
    begin
        if(s==0)
        f=w[1];
        else 
        f=w[0];
        end
endmodule