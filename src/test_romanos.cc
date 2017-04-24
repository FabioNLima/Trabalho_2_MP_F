#include "romanos.h"
#include <string.h>
#include <stdio.h>
#include "gtest/gtest.h"

TEST (Verifica_D, Return_0) { 
    
    char algarismo[] = "D";

    EXPECT_EQ (0, verifica_D(algarismo, 1));
}

TEST (Verifica_DCLIX, Return_0) { 
    
    char algarismo[] = "DCLIX";

    EXPECT_EQ (0, verifica_D(algarismo, 1));
}

TEST (Verifica_DCLXI, Return_0) { 
    
    char algarismo[] = "DCLXI";

    EXPECT_EQ (0, verifica_D(algarismo, 1));
}

TEST (Verifica_DCLXII, Return_0) { 
    
    char algarismo[] = "DCLXII";

    EXPECT_EQ (0, verifica_D(algarismo, 1));
}

TEST (Verifica_DCLXIII, Return_0) { 
    
    char algarismo[] = "DCLXIII";

    EXPECT_EQ (0, verifica_D(algarismo, 1 ));
}

TEST (Verifica_DCXIIII, Return_0) { 
    
    char algarismo[] = "DCXIIII";

    EXPECT_EQ (-1, verifica_D(algarismo, 1));
}

TEST (Verifica_DCL, Return_0) { 
    
    char algarismo[] = "DCL";

    EXPECT_EQ (0, verifica_D(algarismo, 1));
}

TEST (Verifica_DCLX, Return_0) { 
    
    char algarismo[] = "DCLX";

    EXPECT_EQ (0, verifica_D(algarismo, 1));
}

TEST (Verifica_DCLL, Return_0) { 
    
    char algarismo[] = "DCLL";

    EXPECT_EQ (-1, verifica_D(algarismo, 1));
}

TEST (Verifica_DCLXCC, Return_0) { 
    
    char algarismo[] = "DCLXCC";

    EXPECT_EQ (-1, verifica_D(algarismo, 1));
}




/*Testes responsável para verificar o retorno correto
    * do resultado da conversão*/

TEST (Converte_D, Return_valor) { 
    
    char algarismo[] = "D";

    EXPECT_EQ (500, converte(algarismo));
}

TEST (Converte_DCLIX, Return_valor) { 
    
    char algarismo[] = "DCLIX";

    EXPECT_EQ (659, converte(algarismo));
}

TEST (Converte_DCLXI, Return_valor) { 
    
    char algarismo[] = "DCLXI";

    EXPECT_EQ (661, converte(algarismo));
}

TEST (Converte_DCLXII, Return_valor) { 
    
    char algarismo[] = "DCLXII";

    EXPECT_EQ (662, converte(algarismo));
}

TEST (Converte_DCLXIII, Return_valor) { 
    
    char algarismo[] = "DCLXIII";

    EXPECT_EQ (663, converte(algarismo));
}

TEST (Converte_DCLXX, Return_valor) { 
    
    char algarismo[] = "DCLXX";

    EXPECT_EQ (670, converte(algarismo));
}


TEST (Converte_DCLXXX, Return_valor) { 
    
    char algarismo[] = "DCLXXX";

    EXPECT_EQ (680, converte(algarismo));
}




















