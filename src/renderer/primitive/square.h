
#ifndef _RENDERER_PRIMITIVE_SQUARE_H_
#define _RENDERER_PRIMITIVE_SQUARE_H_

#include <vector>

#include "../vertex.h"
#include "../mesh.h"

namespace aker {

    class Square : public Mesh {
        public:
        Square(const std::string& name = "Unnamed Square")
            : Mesh(name)
        {
            std::vector<Vertex> verts = {
                {-0.5f, -0.5f, 0.0f},
                {-0.5f, 0.5f, 0.0f},
                {0.5f, -0.5f, 0.0f},

                {-0.5f, 0.5f, 0.0f},
                {0.5f,  0.5f, 0.0f},
                {0.5f, -0.5f, 0.0f}
            };

            SetVerts(verts);
        };
    };

}
#endif