#ifndef _RENDERER_VERTEX_H_
#define _RENDERER_VERTEX_H_

namespace aker{

	struct Vertex {
		float position[3];
		float normal[3];

		static int Size() { return sizeof(Vertex); };
	};

}

#endif
