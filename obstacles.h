
typedef struct Obstacle Obstacle;
typedef struct Vertex Vertex;
typedef struct Neighbour Neighbour;
typedef struct Environment Environment;

extern int createVertices(Environment *environment);
extern int createEdges(Environment *environment);
extern int removeEdges(Environment *environment);
extern void cleanupEverything(Environment *environment);

struct Obstacle{
  int x;
  int y;
  int w;
  int h;
};

struct Vertex{
  int x;
  int y;
  Neighbour *firstNeighbour;
  Neighbour *lastNeighbour;
};

struct Neighbour{
  Vertex *vertex;
  Neighbour *next;
};

struct Environment{
  Obstacle *obstacles;
  int numObstacles;
  Vertex *vertices;
  int numVertices;
};
