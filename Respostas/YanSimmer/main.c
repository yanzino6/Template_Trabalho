#include "manutencao.h"
#include "pessoa.h"
#include "tecnico.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    Pessoa *p;
    p=lePessoa();
    leTecnico(p);
    setaFuncsPessoa(p,desalocaTecnico,imprimeTecnico,getTipoTecnico);
    imprimePessoa(p);
    desalocaPessoa(p);

    return 0;
}