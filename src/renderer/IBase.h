#ifndef _RENDERER_BASE_H_
#define _RENDERER_BASE_H_

namespace aker
{
	class IBase {
	public:
		IBase() {};
		virtual ~IBase() {};
		virtual unsigned int GetId() const = 0;
	private:
		unsigned int opengl_id_ = -1;
		virtual void Create_() = 0;
		virtual void Delete_() = 0;
	};

}

#endif