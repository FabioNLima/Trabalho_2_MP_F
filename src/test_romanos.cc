#include "romanos.h"
#include <string.h>
#include <stdio.h>
#include "gtest/gtest.h"


/** @file test_romanos.cc
*   @brief Arquivo de testes relativos a romanos.cc
*   @sa romanos.h
*/

/** @fn TEST(Verifica_função relacionada, Return_0)
*   @brief Testes relativos à escrita de uma algarismo romano.
*/

/*Todos os testes a seguir
    * apenas verificar se o algarismo digitado está correto
    * se estiver correto a função é validada e retorna 0
    *caso contrário retorna -1*/

TEST (Verifica_I, Return_0) { 
    
    char algarismo[] = "I";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_IV, Return_0) { 
    
    char algarismo[] = "IV";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}



TEST (Verifica_IIII, Return_0) { 
    
    char algarismo[] = "IIIII";

    EXPECT_EQ (-1, verifica_M(algarismo, 1));
}

TEST (Verifica_IIV, Return_0) { 
    
    char algarismo[] = "IIV";

    EXPECT_EQ (-1, verifica_M(algarismo, 1));
}

TEST (Verifica_IC, Return_0) { 
    
    char algarismo[] = "IC";

    EXPECT_EQ (-1, verifica_M(algarismo, 1));
}


TEST (Verifica_V, Return_0) { 
    
    char algarismo[] = "V";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_VI, Return_0) { 
    
    char algarismo[] = "VI";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}


TEST (Verifica_VII, Return_0) { 
    
    char algarismo[] = "VII";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_VV, Return_0) { 
    
    char algarismo[] = "VV";

    EXPECT_EQ (-1, verifica_M(algarismo, 1));
}

TEST (Verifica_X, Return_0) { 
    
    char algarismo[] = "X";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_IX, Return_0) { 
    
    char algarismo[] = "IX";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_XI, Return_0) { 
    
    char algarismo[] = "XI";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_XIV, Return_0) { 
    
    char algarismo[] = "XIV";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_XIX, Return_0) { 
    
    char algarismo[] = "XIX";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_XXV, Return_0) { 
    
    char algarismo[] = "XXV";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_XXIX, Return_0) { 
    
    char algarismo[] = "XXIX";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_L, Return_0) { 
    
    char algarismo[] = "L";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_LIV, Return_0) { 
    
    char algarismo[] = "LIV";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_LIX, Return_0) { 
    
    char algarismo[] = "LIX";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_LXIV, Return_0) { 
    
    char algarismo[] = "LXIV";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_LXXIX, Return_0) { 
    
    char algarismo[] = "LXXIX";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_LL, Return_0) { 
    
    char algarismo[] = "LL";

    EXPECT_EQ (-1, verifica_M(algarismo, 1));
}


TEST (Verifica_C, Return_0) { 
    
    char algarismo[] = "C";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_CIV, Return_0) { 
    
    char algarismo[] = "CIV";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_CCCLXXXVIII, Return_0) { 
    
    char algarismo[] = "CCCLXXXVIII";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_XC, Return_0) { 
    
    char algarismo[] = "XC";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}


TEST (Verifica_CCCC, Return_0) { 
    
    char algarismo[] = "CCCC";

    EXPECT_EQ (-1, verifica_M(algarismo, 1));
}


TEST (Verifica_CD, Return_0) { 
    
    char algarismo[] = "CD";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}


TEST (Verifica_D, Return_0) { 
    
    char algarismo[] = "D";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}


TEST (Verifica_DC, Return_0) { 
    
    char algarismo[] = "DC";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}


TEST (Verifica_DD, Return_0) { 
    
    char algarismo[] = "DD";

    EXPECT_EQ (-1, verifica_M(algarismo, 1));
}


TEST (Verifica_DCCCLXXXVIII, Return_0) { 
    
    char algarismo[] = "DCCCLXXXVIII";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}

TEST (Verifica_DCCC, Return_0) { 
    
    char algarismo[] = "DCCC";

    EXPECT_EQ (0, verifica_M(algarismo, 1));
}


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


/** @fn TEST(Converte_função relacionada, Return_0)
*   @brief Testes relativos à conversão do algarismo romano para arabico
*/

/*Todos os testes a seguir
    * apenas verificar se o algarismo digitado está correto
    * se estiver correto a função é validada e retorna 0
    *caso contrário retorna -1*/
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




















