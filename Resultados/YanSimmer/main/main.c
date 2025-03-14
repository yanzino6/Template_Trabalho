#include "manutencao.h"
#include "pessoa.h"
#include "tecnico.h"
#include "data.h"
#include"usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    Pessoa *p;
    p=lePessoa();
    leUsuario(p);
    setaFuncsPessoa(p,desalocaUsuario,imprimeUsuario,getTipoUsuario);
    imprimePessoa(p);
    desalocaPessoa(p);

    return 0;
}