#include "manutencao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    Manutencao *outro;
    outro = leManutencao();
    notificaManutencao(outro);
    desalocaManutencao(outro);
    return 0;
}