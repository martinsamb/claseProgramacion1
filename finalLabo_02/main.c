#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Entrega.h"
#include "Informes.h"
#include "utn.h"

int main()
{
    LinkedList* lista = ll_newLinkedList();
    controllerEntrega_loadFromText("data.csv", lista);
    informeEntrega_saveAsText("info.txt",lista);


    return 0;
}

