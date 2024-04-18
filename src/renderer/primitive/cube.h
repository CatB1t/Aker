#ifndef _RENDERER_PRIMITIVE_CUBE_H_
#define _RENDERER_PRIMITIVE_CUBE_H_

#include <vector>

#include "../vertex.h"
#include "../mesh.h"

namespace aker {

    class Cube : public Mesh {
        public:
        Cube() 
        {
            std::vector<Vertex> verts = {
				{-0.5f, -0.5f, -0.5f, },
				{0.5f, -0.5f, -0.5f,  },
				{0.5f,  0.5f, -0.5f,  },
				{0.5f,  0.5f, -0.5f,  },
				{-0.5f,  0.5f, -0.5f, }, 
				{-0.5f, -0.5f, -0.5f, },

				{-0.5f, -0.5f,  0.5f, }, 
				{0.5f, -0.5f,  0.5f,  },
				{0.5f,  0.5f,  0.5f,  },
				{0.5f,  0.5f,  0.5f,  },
				{-0.5f,  0.5f,  0.5f, },
				{-0.5f, -0.5f,  0.5f, }, 

				{-0.5f,  0.5f,  0.5f, }, 
				{-0.5f,  0.5f, -0.5f, }, 
				{-0.5f, -0.5f, -0.5f, },
				{-0.5f, -0.5f, -0.5f, },
				{-0.5f, -0.5f,  0.5f, }, 
				{-0.5f,  0.5f,  0.5f, },

				{0.5f,  0.5f,  0.5f,  },
				{0.5f,  0.5f, -0.5f,  },
				{0.5f, -0.5f, -0.5f,  },
				{0.5f, -0.5f, -0.5f,  },
				{0.5f, -0.5f,  0.5f,  },
				{0.5f,  0.5f,  0.5f,  },

				{-0.5f, -0.5f, -0.5f, }, 
				{0.5f, -0.5f, -0.5f,  },
				{0.5f, -0.5f,  0.5f,  },
				{0.5f, -0.5f,  0.5f,  },
				{-0.5f, -0.5f,  0.5f, }, 
				{-0.5f, -0.5f, -0.5f, }, 

				{-0.5f,  0.5f, -0.5f, }, 
				{0.5f,  0.5f, -0.5f,  },
				{0.5f,  0.5f,  0.5f,  },
				{0.5f,  0.5f,  0.5f,  },
				{-0.5f,  0.5f,  0.5f, }, 
				{-0.5f,  0.5f, -0.5f, } 
            };

            SetVerts(verts);
        }
    };

}
#endif