#include "romanos.h"
#include <string.h>
#include <stdio.h>
#include "gtest/gtest.h"

TEST (Verifica_C, Return_0) { 
    
    char algarismo[] = "C";

    EXPECT_EQ (0, verifica_C(algarismo, 1));
}

TEST (Verifica_CLIX, Return_0) { 
    
    char algarismo[] = "CLIX";

    EXPECT_EQ (0, verifica_C(algarismo, 1));
}

TEST (Verifica_CLXI, Return_0) { 
    
    char algarismo[] = "CLXI";

    EXPECT_EQ (0, verifica_C(algarismo, 1));
}

TEST (Verifica_CLXII, Return_0) { 
    
    char algarismo[] = "CLXII";

    EXPECT_EQ (0, verifica_C(algarismo, 1));
}

TEST (Verifica_CLXIII, Return_0) { 
    
    char algarismo[] = "CLXIII";

    EXPECT_EQ (0, verifica_C(algarismo,1 ));
}

TEST (Verifica_CXIIII, Return_0) { 
    
    char algarismo[] = "CXIIII";

    EXPECT_EQ (-1, verifica_C(algarismo, 1));
}

TEST (Verifica_CL, Return_0) { 
    
    char algarismo[] = "CL";

    EXPECT_EQ (0, verifica_C(algarismo, 1));
}

TEST (Verifica_CLX, Return_0) { 
    
    char algarismo[] = "CLX";

    EXPECT_EQ (0, verifica_C(algarismo, 1));
}

TEST (Verifica_CLL, Return_0) { 
    
    char algarismo[] = "CLL";

    EXPECT_EQ (-1, verifica_C(algarismo, 1));
}

TEST (Verifica_CLXCC, Return_0) { 
    
    char algarismo[] = "CLXCC";

    EXPECT_EQ (-1, verifica_C(algarismo, 1));
}




/*Testes responsável para verificar o retorno correto
    * do resultado da conversão*/

TEST (Converte_C, Return_valor) { 
    
    char algarismo[] = "C";

    EXPECT_EQ (100, converte(algarismo));
}

TEST (Converte_CLIX, Return_valor) { 
    
    char algarismo[] = "CLIX";

    EXPECT_EQ (159, converte(algarismo));
}

TEST (Converte_CLXI, Return_valor) { 
    
    char algarismo[] = "CLXI";

    EXPECT_EQ (161, converte(algarismo));
}

TEST (Converte_CLXII, Return_valor) { 
    
    char algarismo[] = "CLXII";

    EXPECT_EQ (162, converte(algarismo));
}

TEST (Converte_CLXIII, Return_valor) { 
    
    char algarismo[] = "CLXIII";

    EXPECT_EQ (163, converte(algarismo));
}

TEST (Converte_LXX, Return_valor) { 
    
    char algarismo[] = "CLXX";

    EXPECT_EQ (170, converte(algarismo));
}


TEST (Converte_CLXXX, Return_valor) { 
    
    char algarismo[] = "CLXXX";

    EXPECT_EQ (180, converte(algarismo));
}




















