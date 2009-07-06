/*
 * Copyright (C) 2006-2009 Anders Brander <anders@brander.dk> and 
 * Anders Kvist <akv@lnxbx.dk>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef RS_FILTER_RESPONSE_H
#define RS_FILTER_RESPONSE_H

#include <glib-object.h>
#include <gtk/gtk.h>
#include <rs-types.h>

G_BEGIN_DECLS

#define RS_TYPE_FILTER_RESPONSE rs_filter_response_get_type()
#define RS_FILTER_RESPONSE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RS_TYPE_FILTER_RESPONSE, RSFilterResponse))
#define RS_FILTER_RESPONSE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RS_TYPE_FILTER_RESPONSE, RSFilterResponseClass))
#define RS_IS_FILTER_RESPONSE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RS_TYPE_FILTER_RESPONSE))
#define RS_IS_FILTER_RESPONSE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RS_TYPE_FILTER_RESPONSE))
#define RS_FILTER_RESPONSE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RS_TYPE_FILTER_RESPONSE, RSFilterResponseClass))

typedef struct _RSFilterResponse RSFilterResponse;

typedef struct {
  GObjectClass parent_class;
} RSFilterResponseClass;

GType rs_filter_response_get_type(void);

/**
 * Instantiate a new RSFilterResponse object
 * @return A new RSFilterResponse with a refcount of 1
 */
RSFilterResponse *rs_filter_response_new(void);

/**
 * Clone all flags of a RSFilterResponse EXCEPT images
 * @param filter_response A RSFilterResponse
 * @return A new RSFilterResponse with a refcount of 1
 */
RSFilterResponse *rs_filter_response_clone(RSFilterResponse *filter_response);

/**
 * Set the ROI used in generating the response, if the whole image is
 * generated, this should NOT be set
 * @param filter_response A RSFilterResponse
 * @param roi A GdkRectangle describing the ROI or NULL to indicate complete
 *            image data
 */
void rs_filter_response_set_roi(RSFilterResponse *filter_response, GdkRectangle *roi);

/**
 * Get the ROI of the response
 * @param filter_response A RSFilterResponse
 * @return A GdkRectangle describing the ROI or NULL if the complete image is rendered
 */
GdkRectangle *rs_filter_response_get_roi(const RSFilterResponse *filter_response);

/**
 * Set quick flag on a response, this should be set if the image has been
 * rendered by any quick method and a better method is available
 * @note There is no boolean parameter, it would make no sense to remove a
 *       quick-flag
 * @param filter_response A RSFilterResponse
 */
void rs_filter_response_set_quick(RSFilterResponse *filter_response);

/**
 * Get the quick flag
 * @param filter_response A RSFilterResponse
 * @return TRUE if the image data was rendered using a "quick" algorithm and a
 *         faster is available, FALSE otherwise
 */
gboolean rs_filter_response_get_quick(const RSFilterResponse *filter_response);

/**
 * Set 16 bit image data
 * @param filter_response A RSFilterResponse
 * @param image A RS_IMAGE16
 */
void rs_filter_response_set_image(RSFilterResponse *filter_response, RS_IMAGE16 *image);

/**
 * Get 16 bit image data
 * @param filter_response A RSFilterResponse
 * @return A RS_IMAGE16 (must be unreffed after usage) or NULL if none is set
 */
RS_IMAGE16 *rs_filter_response_get_image(const RSFilterResponse *filter_response);

/**
 * Set 8 bit image data
 * @param filter_response A RSFilterResponse
 * @param pixbuf A GdkPixbuf
 */
void rs_filter_response_set_image8(RSFilterResponse *filter_response, GdkPixbuf *pixbuf);

/**
 * Get 8 bit image data
 * @param filter_response A RSFilterResponse
 * @return A GdkPixbuf (must be unreffed after usage) or NULL if none is set
 */
GdkPixbuf *rs_filter_response_get_image8(const RSFilterResponse *filter_response);

G_END_DECLS

#endif /* RS_FILTER_RESPONSE_H */