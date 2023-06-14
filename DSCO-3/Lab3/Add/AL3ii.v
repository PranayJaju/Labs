module AL3ii(A, B, C, D, f);
    input A, B, C, D;
    output f;
    assign f=(A&B&~C)|(B&~C&D)|(A&~B&D)|(A&C&~D)|(~A&B&C)|(~A&C&D);
endmodule 