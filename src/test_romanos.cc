#include "romanos.h"
#include <string.h>
#include <stdio.h>
#include "gtest/gtest.h"

TEST (Verifica_M, Return_0) { 
    
    char algarismo[] = "M";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_MDCLIX, Return_0) { 
    
    char algarismo[] = "MDCLIX";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_MDCLXI, Return_0) { 
    
    char algarismo[] = "MDCLXI";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_MDCLXII, Return_0) { 
    
    char algarismo[] = "MCLXII";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_MDCLXIII, Return_0) { 
    
    char algarismo[] = "MDCLXIII";

    EXPECT_EQ (0, verifica_M(algarismo, 1 ));
}

TEST (Verifica_MDCXIIII, Return_0) { 
    
    char algarismo[] = "MDCXIIII";

    EXPECT_EQ (-1, verifica_M(algarismo, 1));
}

TEST (Verifica_MDCL, Return_0) { 
    
    char algarismo[] = "MDCL";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_MDCLX, Return_0) { 
    
    char algarismo[] = "MDCLX";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_MDCLL, Return_0) { 
    
    char algarismo[] = "MDCLL";

    EXPECT_EQ (-1, verifica_D(algarismo, 1));
}

TEST (Verifica_MDCLXCC, Return_0) { 
    
    char algarismo[] = "MDCLXCC";

    EXPECT_EQ (-1, verifica_D(algarismo, 1));
}




/*Testes responsável para verificar o retorno correto
    * do resultado da conversão*/

TEST (Converte_M, Return_valor) { 
    
    char algarismo[] = "M";

    EXPECT_EQ (1000, converte(algarismo));
}

TEST (Converte_MDCLIX, Return_valor) { 
    
    char algarismo[] = "MDCLIX";

    EXPECT_EQ (1659, converte(algarismo));
}

TEST (Converte_MDCLXI, Return_valor) { 
    
    char algarismo[] = "MDCLXI";

    EXPECT_EQ (1661, converte(algarismo));
}

TEST (Converte_MDCLXII, Return_valor) { 
    
    char algarismo[] = "MDCLXII";

    EXPECT_EQ (1662, converte(algarismo));
}

TEST (Converte_MDCLXIII, Return_valor) { 
    
    char algarismo[] = "MDCLXIII";

    EXPECT_EQ (1663, converte(algarismo));
}

TEST (Converte_MDCLXX, Return_valor) { 
    
    char algarismo[] = "MDCLXX";

    EXPECT_EQ (1670, converte(algarismo));
}


TEST (Converte_MDCLXXX, Return_valor) { 
    
    char algarismo[] = "MDCLXXX";

    EXPECT_EQ (1680, converte(algarismo));
}




















