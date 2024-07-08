#include <stdio.h>
#include <stdlib.h>

#include "obstacles.h"
#include "display.h"

int createVertices(Environment *environment){
  environment->numVertices = environment->numObstacles*4;

  environment->vertices = malloc(sizeof(Vertex) * (environment->numVertices));

  if(environment->vertices == NULL){
    printf("Memory allocation error\n");
    exit(0);
  }

  int j = 0;

  while(j < environment->numObstacles){
    for(int i = 0; i < environment->numVertices; i+=4){

      int x = environment->obstacles[j].x;
      int y = environment->obstacles[j].y;

      //top left Vertex
      environment->vertices[i].x = x;
      environment->vertices[i].y = y;

      //top right Vertex
      environment->vertices[i + 1].x = x + environment->obstacles[j].w;
      environment->vertices[i + 1].y = y;

      //bottom left Vertex
      environment->vertices[i + 2].x = x;
      environment->vertices[i + 2].y = y - environment->obstacles[j].h;

      //bottom right Vertex
      environment->vertices[i + 3].x = x + environment->obstacles[j].w;
      environment->vertices[i + 3].y = y - environment->obstacles[j].h;

      j++;
    }
  }


  return environment->numVertices;
}

int createEdges(Environment *environment){

    for (int i = 0; i < environment->numVertices-1; i++)
    {
        for (int j = 0; j < environment->numVertices; j)
        {
            Neighbour *newNeighbour = (Neighbour *)malloc(sizeof(Neighbour));
            newNeighbour->vertex = &environment->vertices[j];
            newNeighbour->next = &environment->vertices[i+1].firstNeighbour;
            environment->vertices[i].firstNeighbour=newNeighbour;
        }
        
        
        
    }
    
    return 0;
}

int removeEdges(Environment *environment){
  return 0;
}

void cleanupEverything(Environment *environment){

}