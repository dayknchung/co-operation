/**

GDevelop - Draggable Behavior Extension
Copyright (c) 2013-2016 Florian Rival (Florian.Rival@gmail.com)
This project is released under the MIT License.
*/

#ifndef DRAGGABLEBEHAVIOR_H
#define DRAGGABLEBEHAVIOR_H
#include <SFML/System/Vector2.hpp>
#include <map>
#include "GDCpp/Runtime/Project/Behavior.h"
#include "GDCpp/Runtime/Project/Object.h"
class RuntimeScene;
namespace gd {
class SerializerElement;
}
namespace gd {
class Layout;
}

/**
 * \brief Behavior that allows objects to be dragged with the mouse
 */
class GD_EXTENSION_API DraggableBehavior : public Behavior {
 public:
  DraggableBehavior();
  virtual ~DraggableBehavior(){};
  virtual Behavior* Clone() const { return new DraggableBehavior(*this); }

  /**
   * \brief Return true if the object is being dragged.
   */
  bool IsDragged() const { return dragged; };

  virtual void OnDeActivate();

 private:
  virtual void DoStepPreEvents(RuntimeScene& scene);
  virtual void DoStepPostEvents(RuntimeScene& scene);

  float xOffset;
  float yOffset;
  std::size_t dragCameraIndex;  ///< The camera being used to move the object. (
                                ///< The layer is the object's layer ).
  bool dragged;                 ///< True if the object is being dragged.
  static bool somethingDragged;  ///< Used to avoid start dragging an object
                                 ///< while another is being dragged.
  static bool
      leftPressedLastFrame;  ///< Used to only start dragging when clicking.
};

#endif  // DRAGGABLEBEHAVIOR_H
