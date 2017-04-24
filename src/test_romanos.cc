#include "romanos.h"
#include <string.h>
#include <stdio.h>
#include "gtest/gtest.h"

TEST (Verifica_X, Return_0) { 
    
    char algarismo[] = "X";

    EXPECT_EQ (0, verifica_X(algarismo, 1));
}

TEST (Verifica_IX, Return_0) { 
    
    char algarismo[] = "IX";

    EXPECT_EQ (0, verifica_X(algarismo, 1));
}

TEST (Verifica_XI, Return_0) { 
    
    char algarismo[] = "XI";

    EXPECT_EQ (0, verifica_X(algarismo, 1));
}

TEST (Verifica_XII, Return_0) { 
    
    char algarismo[] = "XII";

    EXPECT_EQ (0, verifica_X(algarismo, 1));
}

TEST (Verifica_XIII, Return_0) { 
    
    char algarismo[] = "XIII";

    EXPECT_EQ (0, verifica_X(algarismo,1 ));
}

TEST (Verifica_XIIII, Return_0) { 
    
    char algarismo[] = "XIIII";

    EXPECT_EQ (-1, verifica_X(algarismo, 1));
}

TEST (Verifica_XC, Return_0) { 
    
    char algarismo[] = "XC";

    EXPECT_EQ (0, verifica_X(algarismo, 1));
}

TEST (Verifica_XL, Return_0) { 
    
    char algarismo[] = "XL";

    EXPECT_EQ (0, verifica_X(algarismo, 1));
}

TEST (Verifica_XLL, Return_0) { 
    
    char algarismo[] = "XLL";

    EXPECT_EQ (-1, verifica_X(algarismo, 1));
}

TEST (Verifica_XCC, Return_0) { 
    
    char algarismo[] = "XXCC";

    EXPECT_EQ (-1, verifica_X(algarismo, 1));
}






TEST (Converte_X, Return_valor) { 
    
    char algarismo[] = "X";

    EXPECT_EQ (10, converte(algarismo));
}

TEST (Converte_IX, Return_valor) { 
    
    char algarismo[] = "IX";

    EXPECT_EQ (9, converte(algarismo));
}

TEST (Converte_XI, Return_valor) { 
    
    char algarismo[] = "XI";

    EXPECT_EQ (11, converte(algarismo));
}

TEST (Converte_XII, Return_valor) { 
    
    char algarismo[] = "XII";

    EXPECT_EQ (12, converte(algarismo));
}

TEST (Converte_XIII, Return_valor) { 
    
    char algarismo[] = "XIII";

    EXPECT_EQ (13, converte(algarismo));
}

TEST (Converte_XL, Return_valor) { 
    
    char algarismo[] = "XL";

    EXPECT_EQ (40, converte(algarismo));
}


TEST (Converte_XC, Return_valor) { 
    
    char algarismo[] = "XC";

    EXPECT_EQ (90, converte(algarismo));
}




















