module sistema_total4 (
    input wire clk,
    input wire reset_btn,
    input wire [4:0] sensores,
    output reg [4:0] led,
    output reg [7:0] salida,
    output reg [2:0] seg
);

    wire reset;
    assign reset = ~reset_btn;

    // =========================================================
    // 1 SEGUNDO
    // =========================================================
    parameter ONE_SEC = 12000000;

    reg [23:0] cont_1s;
    reg tick_1s;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            cont_1s <= 0;
            tick_1s <= 0;
        end else begin
            if (cont_1s >= ONE_SEC-1) begin
                cont_1s <= 0;
                tick_1s <= 1;
            end else begin
                cont_1s <= cont_1s + 1;
                tick_1s <= 0;
            end
        end
    end

    reg [2:0] countdown;

    // =========================================================
    // CONTROL DE JUEGO
    // =========================================================
    parameter Time1 = 24000000;
    parameter Time2 = 12000000;
    parameter Time3 = 6000000;

    reg [24:0] contador;
    reg [24:0] tiempo;
    reg [5:0] ronda;
    reg tick;
    reg juego_activo;
    reg en_countdown;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            contador <= 0;
            tick <= 0;
            tiempo <= Time1;
            ronda <= 0;
            juego_activo <= 0;
            en_countdown <= 1;
            countdown <= 3;
        end else begin

            if (en_countdown) begin
                if (tick_1s) begin
                    if (countdown == 0) begin
                        en_countdown <= 0;
                        juego_activo <= 1;
                    end else begin
                        countdown <= countdown - 1;
                    end
                end
            end

            else if (juego_activo) begin
                if (contador >= tiempo - 1) begin
                    contador <= 0;
                    tick <= 1;

                    if (ronda == 9)
                        tiempo <= Time2;
                    else if (ronda == 19)
                        tiempo <= Time3;

                    if (ronda == 29)
                        juego_activo <= 0;

                    ronda <= ronda + 1;

                end else begin
                    contador <= contador + 1;
                    tick <= 0;
                end
            end else begin
                tick <= 0;
            end
        end
    end

    // =========================================================
    // NIVEL
    // =========================================================
    reg [3:0] nivel;

    always @(posedge clk) begin
        if (ronda < 10)
            nivel <= 1;
        else if (ronda < 20)
            nivel <= 2;
        else
            nivel <= 3;
    end

    // =========================================================
    // TIMER 5s (FIX REAL)
    // =========================================================
    parameter FIVE_SEC = 60000000;

    reg [25:0] cont_5s;
    reg ya_contado;
    reg fin_total;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            cont_5s <= 0;
            ya_contado <= 0;
            fin_total <= 0;
        end 
        else if (!juego_activo && !en_countdown && !ya_contado) begin
            if (cont_5s >= FIVE_SEC-1) begin
                cont_5s <= 0;
                ya_contado <= 1;
                fin_total <= 1; // se queda fijo
            end else begin
                cont_5s <= cont_5s + 1;
            end
        end 
        else if (juego_activo) begin
            cont_5s <= 0;
            ya_contado <= 0;
            fin_total <= 0;
        end
    end

    // =========================================================
    // BLINK (FIX)
    // =========================================================
    reg [20:0] blink_counter;
    reg blink;

    always @(posedge clk) begin
        if (!juego_activo && !en_countdown && !fin_total) begin
            if (blink_counter >= 1200000) begin
                blink_counter <= 0;
                blink <= ~blink;
            end else begin
                blink_counter <= blink_counter + 1;
            end
        end else begin
            blink_counter <= 0;
            blink <= 0;
        end
    end

    // =========================================================
    // LFSR + LEDS (solo cambio fin_total)
    // =========================================================
    reg [7:0] lfsr [4:0];
    wire [4:0] fb;

    assign fb[0] = lfsr[0][7]^lfsr[0][5]^lfsr[0][4]^lfsr[0][3];
    assign fb[1] = lfsr[1][7]^lfsr[1][5]^lfsr[1][4]^lfsr[1][3];
    assign fb[2] = lfsr[2][7]^lfsr[2][5]^lfsr[2][4]^lfsr[2][3];
    assign fb[3] = lfsr[3][7]^lfsr[3][5]^lfsr[3][4]^lfsr[3][3];
    assign fb[4] = lfsr[4][7]^lfsr[4][5]^lfsr[4][4]^lfsr[4][3];

    integer i;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            led <= 0;
            lfsr[0] <= 8'hA5;
            lfsr[1] <= 8'h3C;
            lfsr[2] <= 8'hF1;
            lfsr[3] <= 8'h77;
            lfsr[4] <= 8'h9B;
        end 
        else if (!juego_activo && !en_countdown) begin
            if (!fin_total)
                led <= blink ? 5'b11111 : 5'b00000;
            else
                led <= 5'b00000;
        end 
        else if (tick) begin
            for (i = 0; i < 5; i = i + 1) begin
                lfsr[i] <= {lfsr[i][6:0], fb[i]};
                led[i] <= lfsr[i][0];
            end
        end
    end

    // =========================================================
    // FLANCO (TU CÓDIGO ORIGINAL)
    // =========================================================
    reg s0 [4:0];
    reg s1 [4:0];
    reg [15:0] filtro [4:0];
    reg estado [4:0];
    reg estado_prev [4:0];
    wire [4:0] flanco;

    genvar k;
    generate
        for (k = 0; k < 5; k = k + 1) begin : sensores_block

            always @(posedge clk) begin
                s0[k] <= sensores[k];
                s1[k] <= s0[k];
            end

            always @(posedge clk) begin
                if (s1[k] == estado[k])
                    filtro[k] <= 0;
                else begin
                    filtro[k] <= filtro[k] + 1;
                    if (filtro[k] == 50000) begin
                        estado[k] <= s1[k];
                        filtro[k] <= 0;
                    end
                end
            end

            always @(posedge clk)
                estado_prev[k] <= estado[k];

            assign flanco[k] = (estado_prev[k] == 1) && (estado[k] == 0);

        end
    endgenerate

    // =========================================================
    // CONTADOR (SOLO CAMBIO fin_total)
    // =========================================================
    reg [3:0] unidades;
    reg [3:0] decenas;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            unidades <= 0;
            decenas <= 0;
        end 

        else if (juego_activo) begin
            for (i = 0; i < 5; i = i + 1) begin

                if (flanco[i] && led[i]) begin
                    if (unidades == 9) begin
                        unidades <= 0;
                        if (decenas == 9)
                            decenas <= 0;
                        else
                            decenas <= decenas + 1;
                    end else
                        unidades <= unidades + 1;
                end

                else if (flanco[i] && ~led[i]) begin
                    if (!(decenas == 0 && unidades == 0)) begin
                        if (unidades == 0) begin
                            unidades <= 9;
                            decenas <= decenas - 1;
                        end else
                            unidades <= unidades - 1;
                    end
                end

            end
        end

        else if (!fin_total) begin
            unidades <= unidades;
            decenas <= decenas;
        end

        else begin
            unidades <= 0;
            decenas <= 0;
        end
    end

    // =========================================================
    // DISPLAY (INTACTO)
    // =========================================================
    reg [15:0] mux_counter;
    reg [1:0] selector;
    reg [3:0] numero;

    always @(posedge clk) begin
        mux_counter <= mux_counter + 1;

        if (mux_counter == 5000) begin
            mux_counter <= 0;
            selector <= selector + 1;

            case (selector)
                2'b00: begin
                    numero <= unidades;
                    seg <= 3'b011;
                end
                2'b01: begin
                    numero <= decenas;
                    seg <= 3'b101;
                end
                2'b10: begin
                    if (en_countdown)
                        numero <= countdown;
                    else
                        numero <= nivel;
                    seg <= 3'b110;
                end
            endcase
        end
    end

    always @(*) begin
        case (numero)
            0: salida = 8'b11000000;
            1: salida = 8'b11111001;
            2: salida = 8'b10100100;
            3: salida = 8'b10110000;
            4: salida = 8'b10011001;
            5: salida = 8'b10010010;
            6: salida = 8'b10000010;
            7: salida = 8'b11111000;
            8: salida = 8'b10000000;
            9: salida = 8'b10011000;
            default: salida = 8'b11111111;
        endcase
    end

endmodule