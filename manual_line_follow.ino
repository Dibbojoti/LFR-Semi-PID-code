void line_follow() {
  while (1) {
    reading();
    if (sum == 0) {  //sharp turn
      if (turn != 's') {
        delay(node_delay);                                    
        (turn == 'r') ? motor(tsp, -tsp) : motor(-tsp, tsp);  //tsp = turn speed. adjust korte hobe
        while (!s[2] && !s[3]) reading();                     //001100 na howa porjonto reading nibe
        turn = 's';                                           //turn newar por then st. jabe
      }
    }

    else if (sum == 1 || sum == 2) {  //st. line
      if (sensor == 0b001100) {
        if (pos != 0) {
          (pos > 0) ? motor(-10 * lsp, 10 * rsp) : motor(10 * lsp, -10 * rsp);  //bari mara
          delay(abs(pos) * 5);  //speed wise 3,4,5,6 diye adjust korte hobe
        }
        motor(10 * lsp, 10 * rsp); //correction korar por then st. jabe
      }

      //right side turn correction
      else if (sensor == 0b000100)
        motor(10 * lsp, 9 * rsp);

      else if (sensor == 0b000110) {
        if (pos < 1) pos = 1;
        motor(10 * lsp, (9 - line_prop) * rsp);  //line_prop float dite hobe cuz precision 
      }

      else if (sensor == 0b000010) {
        if (pos < 2) pos = 2;
        motor(10 * lsp, (9 - 2 * line_prop) * rsp);
      }

      else if (sensor == 0b000011) {
        if (pos < 3) pos = 3;
        motor(10 * lsp, (9 - 3 * line_prop) * rsp);
      }

      else if (sensor == 0b000001) {
        if (pos < 4) pos = 4;
        motor(10 * lsp, (9 - 4 * line_prop) * rsp);
      }

      //left side turn detection
      else if (sensor == 0b001000)
        motor(9 * lsp, 10 * rsp);

      else if (sensor == 0b011000) {
        if (pos > -1) pos = -1;
        motor((9 - line_prop) * lsp, 10 * rsp);
      }

      else if (sensor == 0b010000) {
        if (pos > -2) pos = -2;
        motor((9 - 2 * line_prop) * lsp, 10 * rsp);
      }

      else if (sensor == 0b110000) {
        if (pos > -3) pos = -3;
        motor((9 - 3 * line_prop) * lsp, 10 * rsp);
      }

      else if (sensor == 0b100000) {
        if (pos > -4) pos = -4;
        motor((9 - 4 * line_prop) * lsp, 10 * rsp);
      }
    }

    else if (sum >= 3 && sum <= 5) {  //sharp turn detect er jonno
      if ((s[2] + s[3]) && s[0] && !s[5]) turn = 'r';
      if ((s[2] + s[3]) && s[5] && !s[0]) turn = 'l';
    }

    else if (sum == 6) {
      delay(200);  //delay adjust korte hobe
      reading();   //T naki stop er jonno ektu pore arekbar reading nibe
      if (sum == 6) {  //shob sensor black hoile stop
        motor(0, 0);
        while (sum == 6) reading();
      } else if (sum == 0) turn = 'r';  //shob sensor white hoile T
    }
  }
}
