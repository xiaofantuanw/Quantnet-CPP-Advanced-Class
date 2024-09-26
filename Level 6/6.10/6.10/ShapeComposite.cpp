#include "ShapeComposite.hpp"
#include "ShapeVisitor.hpp"

void ShapeComposite::Accept(ShapeVisitor* sv)
{
	sv->visit(*this);
}