#ifndef _RENDERER_VERTEX_H_
#define _RENDERER_VERTEX_H_

namespace aker{

	struct Vertex {
		float position[3];
		static int Size() { return sizeof(position); };
	};

}

#endif
