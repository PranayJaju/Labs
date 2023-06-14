module Q1b(X, Y, Z, lhs, rhs);
    input X, Y, Z;
    output lhs, rhs;
    assign lhs=X&(Y|Z);
    assign rhs=(X&Y)|(X&Z);
endmodule    