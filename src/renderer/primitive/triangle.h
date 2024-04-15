#ifndef _RENDERER_PRIMITIVE_TRIANGLE_H_
#define _RENDERER_PRIMITIVE_TRIANGLE_H_

#include <vector>

#include "../vertex.h"
#include "../mesh.h"

namespace aker {

    class Triangle : public Mesh {
        public:
        Triangle() 
        {
            std::vector<Vertex> verts = {
                {-0.5f, -0.5f, 0.0f},
                {0.5f, -0.5f, 0.0f},
                {0.0f,  0.5f, 0.0f}
            };

            SetVerts(verts);
        }
    };

}
#endif