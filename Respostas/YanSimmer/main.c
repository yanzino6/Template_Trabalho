#include "manutencao.h"
#include "pessoa.h"
#include "tecnico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    Pessoa *p;
    p=lePessoa();
    setaFuncsPessoa(p,desalocaTecnico,imprimeTecnico,getTipoTecnico);
    leDadosPessoa(p);
    imprimeTecnico(p);
    desalocaPessoa(p);

    return 0;
}