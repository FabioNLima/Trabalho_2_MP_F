#include "romanos.h"
#include <string.h>
#include <stdio.h>
#include "gtest/gtest.h"

TEST (Verifica_I, Return_0) { 
    
    char algarismo_I[] = "I";

    EXPECT_EQ (0, verifica_I(algarismo_I));
}

TEST (Verifica_II, Return_0) { 
    
    char algarismo_II[] = "II";

    EXPECT_EQ (0, verifica_I(algarismo_II));
}

TEST (Verifica_III, Return_0) { 
    
    char algarismo_III[] = "III";

    EXPECT_EQ (0, verifica_I(algarismo_III));
}

TEST (Verifica_IIII, Return_0) { 
    
    char algarismo_IIII[] = "IIII";

    EXPECT_EQ (-1, verifica_I(algarismo_IIII));
}

TEST (Converte_I, Return_valor) { 
    
    char algarismo_I[] = "I";

    EXPECT_EQ (1, converte(algarismo_I));
}

TEST (Converte_II, Return_valor) { 
    
    char algarismo[] = "II";

    EXPECT_EQ (2, converte(algarismo));
}

TEST (Converte_III, Return_valor) { 
    
    char algarismo[] = "III";

    EXPECT_EQ (3, converte(algarismo));
}

TEST (Converte_IV, Return_valor) { 
    
    char algarismo[] = "IV";

    EXPECT_EQ (4, converte(algarismo));
}

TEST (Converte_IX, Return_valor) { 
    
    char algarismo[] = "IX";

    EXPECT_EQ (9, converte(algarismo));
}























