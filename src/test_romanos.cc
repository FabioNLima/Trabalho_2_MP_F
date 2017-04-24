#include "romanos.h"
#include <string.h>
#include <stdio.h>
#include "gtest/gtest.h"

TEST (Verifica_L, Return_0) { 
    
    char algarismo[] = "L";

    EXPECT_EQ (0, verifica_L(algarismo, 1));
}

TEST (Verifica_LIX, Return_0) { 
    
    char algarismo[] = "LIX";

    EXPECT_EQ (0, verifica_L(algarismo, 1));
}

TEST (Verifica_LXI, Return_0) { 
    
    char algarismo[] = "LXI";

    EXPECT_EQ (0, verifica_L(algarismo, 1));
}

TEST (Verifica_LXII, Return_0) { 
    
    char algarismo[] = "LXII";

    EXPECT_EQ (0, verifica_L(algarismo, 1));
}

TEST (Verifica_LXIII, Return_0) { 
    
    char algarismo[] = "LXIII";

    EXPECT_EQ (0, verifica_L(algarismo,1 ));
}

TEST (Verifica_XIIII, Return_0) { 
    
    char algarismo[] = "LXIIII";

    EXPECT_EQ (-1, verifica_L(algarismo, 1));
}

TEST (Verifica_LXC, Return_0) { 
    
    char algarismo[] = "XC";

    EXPECT_EQ (0, verifica_L(algarismo, 1));
}

TEST (Verifica_LX, Return_0) { 
    
    char algarismo[] = "LX";

    EXPECT_EQ (0, verifica_L(algarismo, 1));
}

TEST (Verifica_LL, Return_0) { 
    
    char algarismo[] = "LL";

    EXPECT_EQ (-1, verifica_L(algarismo, 1));
}

TEST (Verifica_LXCC, Return_0) { 
    
    char algarismo[] = "LXCC";

    EXPECT_EQ (-1, verifica_L(algarismo, 1));
}




/*Testes responsável para verificar o retorno correto
    * do resultado da conversão*/

TEST (Converte_L, Return_valor) { 
    
    char algarismo[] = "L";

    EXPECT_EQ (50, converte(algarismo));
}

TEST (Converte_LIX, Return_valor) { 
    
    char algarismo[] = "LIX";

    EXPECT_EQ (59, converte(algarismo));
}

TEST (Converte_LXI, Return_valor) { 
    
    char algarismo[] = "LXI";

    EXPECT_EQ (61, converte(algarismo));
}

TEST (Converte_LXII, Return_valor) { 
    
    char algarismo[] = "LXII";

    EXPECT_EQ (62, converte(algarismo));
}

TEST (Converte_LXIII, Return_valor) { 
    
    char algarismo[] = "LXIII";

    EXPECT_EQ (63, converte(algarismo));
}

TEST (Converte_LXX, Return_valor) { 
    
    char algarismo[] = "LXX";

    EXPECT_EQ (70, converte(algarismo));
}


TEST (Converte_LXXX, Return_valor) { 
    
    char algarismo[] = "LXXX";

    EXPECT_EQ (80, converte(algarismo));
}




















