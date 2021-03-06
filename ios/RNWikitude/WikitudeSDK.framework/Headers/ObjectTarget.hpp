//
//  ObjectTarget.hpp
//  WikitudeUniversalSDK
//
//  Created by Thibault Jochem on Wed Nov 08 2017
//  Copyright © 2017 Wikitude. All rights reserved.
//

#ifndef OBJECTTARGET_HPP
#define OBJECTTARGET_HPP

#ifdef __cplusplus

#include <string>

#include "Geometry.hpp"


namespace wikitude { namespace sdk {

    namespace impl {


        /** @addtogroup ObjectTracking
        *  @{
        */
        /** @class ObjectTarget
          * @brief A class that represents object targets that are found by an object tracer.
          *
          * Scale values can be used to convert the ‘unit cube’ modelView matrix into a box that covers just the outer 
          * dimensions of the object. Example: Consider a truck like shaped object target. In case a cube
          * with edge length of one would be drawn with the modelView matrix, the cube would be drawn without 
          * distortions in the center of the object. To render a box around the truck, x/y/z scale values are used to
          * create another scale matrix that is multiplied with the given modelView matrix. The result is then a box 
          * that encompasses the object target at it’s outer dimensions.
          */
        class Matrix4;
        class ObjectTarget{
        public:
            virtual ~ObjectTarget() = default;

            /** @brief Gets the name of the associated target object in the wikitude object target collection(.wto).
			 *
			 *	@return The name of the image target.
			 */
            virtual const std::string& getName() const = 0;
            
            /** @brief Gets the depth factor that needs to be applied to the matrix to get real world scaling.
             *
             * Note: This getter only returns valid information in case depth camera information are passed to the SDK.
             *
             * @return The depth factor of the object target.
             */
            virtual float getDepthFactor() const = 0;
            
            /** @brief Gets a scale value that represents the object dimensions proportionally to the uniform scaling
             *  given through the matrix returned from getMatrix();
			 * 
			 * @return The normalized scale of the object target.
			 */
            virtual const Scale3D<float> getTargetScale() const = 0;

            /** @brief Gets the combined modelview matrix that should be applied to augmentations when rendering.
             * In cases where the orientation of the rendering surface and orientation of the camera do not match, and a correct cameraToRenderSurfaceRotation is passed to the SDK,
             * this matrix will also be rotate to account for the mismatch.
             *
             * For example, on mobile devices running in portrait mode, that have a camera sensor is landscape right position, the cameraToRenderSurfaceRotation should be 90 degrees.
             * The matrix will be rotated by 90 degrees around the Z axis.
             *
             * @return The matrix that should be applied to the target augmentation when rendering.
             */
            virtual const Matrix4& getMatrix() const = 0;
        };
        /** @}*/
    }
    using impl::ObjectTarget;
}}

#endif /* __cplusplus */

#endif /* OBJECTTARGET_HPP */
