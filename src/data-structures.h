#define TETROMINO_SIZE 4

class sVector2 {
public:
    short m_x, m_y;
    sVector2();
    sVector2(short x, short y);
};

class block_graph {
    block_graph();
private:
    sVector2 coordinates[TETROMINO_SIZE];
};
