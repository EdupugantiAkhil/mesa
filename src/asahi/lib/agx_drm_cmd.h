/*
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <stddef.h>
#include "drm-uapi/asahi_drm.h"

/* The kernel header defines each command's struct, its optional parts
 * appended in order, and a per-generation tail sent after the complete
 * command (M5's stage prefixes, as G18's resources). A command may end after
 * any optional part; the kernel reads the parts it omits as zero, and
 * kernels that predate a part refuse a command that carries it. These are the
 * sizes a command sends by what it carries, taken from those definitions.
 */

/* Render: the base command, then prior_vdm/prior_cdm (exact priors), then
 * ray_query[2]; M5's struct drm_asahi_render_stage_prefixes follows the
 * complete command (struct drm_asahi_cmd_render_m5). */
#define AGX_DRM_RENDER_SIZE_BASE offsetof(struct drm_asahi_cmd_render, prior_vdm)
#define AGX_DRM_RENDER_SIZE_PRIOR offsetof(struct drm_asahi_cmd_render, ray_query)
#define AGX_DRM_RENDER_SIZE_RAY_QUERY sizeof(struct drm_asahi_cmd_render)
#define AGX_DRM_RENDER_SIZE_FULL sizeof(struct drm_asahi_cmd_render_m5)

/* Compute: the base command, then scs_layout, prior_vdm/prior_cdm and the
 * ray-query state. */
#define AGX_DRM_COMPUTE_SIZE_BASE                                              \
   offsetof(struct drm_asahi_cmd_compute, scs_layout)
#define AGX_DRM_COMPUTE_SIZE_FULL sizeof(struct drm_asahi_cmd_compute)
