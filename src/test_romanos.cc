#include "romanos.h"
#include <string.h>
#include <stdio.h>
#include "gtest/gtest.h"

TEST (Verifica_V, Return_0) { 
    
    char algarismo[] = "V";

    EXPECT_EQ (0, verifica_V(algarismo));
}

TEST (Verifica_IV, Return_0) { 
    
    char algarismo[] = "IV";

    EXPECT_EQ (0, verifica_V(algarismo));
}

TEST (Verifica_VI, Return_0) { 
    
    char algarismo[] = "VI";

    EXPECT_EQ (0, verifica_V(algarismo));
}

TEST (Verifica_VII, Return_0) { 
    
    char algarismo[] = "VII";

    EXPECT_EQ (0, verifica_V(algarismo));
}

TEST (Verifica_VIII, Return_0) { 
    
    char algarismo[] = "VIII";

    EXPECT_EQ (0, verifica_V(algarismo));
}

TEST (Verifica_VIIII, Return_0) { 
    
    char algarismo[] = "VIIII";

    EXPECT_EQ (-1, verifica_V(algarismo));
}









TEST (Converte_V, Return_valor) { 
    
    char algarismo[] = "V";

    EXPECT_EQ (5, converte(algarismo));
}

TEST (Converte_IV, Return_valor) { 
    
    char algarismo[] = "IV";

    EXPECT_EQ (4, converte(algarismo));
}

TEST (Converte_VI, Return_valor) { 
    
    char algarismo[] = "VI";

    EXPECT_EQ (6, converte(algarismo));
}

TEST (Converte_VII, Return_valor) { 
    
    char algarismo[] = "VII";

    EXPECT_EQ (7, converte(algarismo));
}

TEST (Converte_VIII, Return_valor) { 
    
    char algarismo[] = "VIII";

    EXPECT_EQ (8, converte(algarismo));
}























