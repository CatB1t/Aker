#ifndef _RENDERER_IBASE_H_
#define _RENDERER_IBASE_H_

namespace aker
{
	class IBase {
	public:
		IBase() {};
		virtual ~IBase() {};
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		unsigned int GetId() const { return opengl_id_; };
	private:
		unsigned int opengl_id_ = -1;
		virtual void Create_() = 0;
		virtual void Delete_() = 0;
	};

}

#endif