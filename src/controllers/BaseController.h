#ifndef CONTROLLERS_BASE_CONTROLLER_H
#define CONTROLLERS_BASE_CONTROLLER_H

class BaseController {
public:
	virtual ~BaseController() = default;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

#endif

