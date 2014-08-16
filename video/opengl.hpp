
/* bdapi - brain damage api version 0.6.0 */
#ifndef BDAPI_VIDEO_OPENGL_HPP
#define BDAPI_VIDEO_OPENGL_HPP
#include "bdapi.hpp"

/* includes */

// glew
#define GLEW_STATIC
#include "GL/glew.h"

// opengl
#include "GL/GL.h"
#include "GL/GLU.h"

// bdapi
#include "display/handler.hpp"
//#include "math/mob2.hpp"
//#include "math/mob3.hpp"
#include "math/typedefs.hpp"
#include "video/buffer.hpp"
#include "video/color.hpp"
#include "video/handler.hpp"
#include "video/image.hpp"
#include "video/shader.hpp"

/* namespaces */
namespace bdapi {
namespace gl    {

/* opengl handling subsystem extern declarations */

extern f32 vx;
extern f32 vy;
extern f32 vw;
extern f32 vh;

extern f32 tx;
extern f32 ty;
extern f32 tw;
extern f32 th;

/* opengl handling subsystem core function declarations */

void initialize ();

//result init_pipeline ( s32, s32, bl, bl );

void reset (            );
void reset ( bl texture );

void view_2d (                             );
void view_2d ( const video::buffer& buffer );
void view_2d ( s32 width, s32 height       );

//void view_3d ( const math::mob3& mob, f32 fov, f32 distance );

void blend_func ( u8 func );

void set_fog_params ( const video::color& c, f32 strength );

void set_current_image  ( video::image*  video_image  );
void set_current_buffer ( video::buffer* video_buffer );
void set_current_shader ( video::shader* video_shader );

video::image*  get_current_image  ();
video::buffer* get_current_buffer ();
video::shader* get_current_shader ();

video::pipeline* get_pipeline ();

video::raw* save_pixel_data ( s32 x, s32 y, s32 width, s32 height );
video::raw* save_pixel_data (               s32 width, s32 height );
video::raw* save_pixel_data (                                     );

video::raw* print_screen ();

/* opengl handling subsystem inlined function implementations */

// generic toggles
inline bl   is_enabled (GLenum a){if(glIsEnabled(a))return true;return false;};
inline bl   is_disabled(GLenum a){return !is_disabled(a);};
inline void disable    (GLenum a){glDisable(a);};
inline void enable     (GLenum a){glEnable(a);};
inline void enable     (GLenum a,bl b){if(b)enable(a);else disable(a);};

// special case toggles

inline void blend(GLenum a,GLenum b){glBlendFunc(a,b);};

inline void cull_mode(GLenum a){glCullFace(a);};

// attributes
inline void push(GLenum a){glPushAttrib(a);};

// view modes
inline void view (s32 w,s32 h){glViewport(0,0,w,h);};
inline void view (s32 x,s32 y,s32 w,s32 h){glViewport(x,y,w,h);};
inline void ortho(s32 w,s32 h){gluOrtho2D(0,w,h,0);};
inline void ortho(s32 x,s32 y,s32 w,s32 h){gluOrtho2D(x,w,h,y);};

// rendering modes
inline void depth_func (GLenum a){glDepthFunc(a);};
inline void depth_mask (bl a){glDepthMask(a);};
inline void shade_model(bl a){if(a)glShadeModel(GL_SMOOTH);else glShadeModel(GL_FLAT);};

// generic hint
inline void hint(GLenum a,GLenum b){glHint(a,b);}

// matrices

inline void load_identity(){glLoadIdentity();};

inline void matrix_mode(GLenum a){glMatrixMode(a);load_identity();};
inline void matrix(const f32* m){glLoadMatrixf(m);};
inline void matrix(const math::mat4& m){matrix(glm::value_ptr(m));};

inline void push()    {glPushMatrix();};
inline void pop()     {glPopMatrix();};
inline void pop_push(){glPopMatrix();glPushMatrix();};

// colors

inline void bind(video::color& a){a.bind();};

inline void apply_color(video::color& c){c.bind();};
inline void apply_color(f32 r,f32 g,f32 b){video::color(r,g,b).bind();};
inline void apply_color(f32 r,f32 g,f32 b, f32 a){video::color(r,g,b,a).bind();};

inline void clear_color(video::color& c){c.bind_clear();};
inline void clear_color(f32 r,f32 g,f32 b){video::color(r,g,b).bind_clear();};
inline void clear_color(f32 r,f32 g,f32 b,f32 a){video::color(r,g,b,a).bind_clear();};

inline void black(){apply_color(0.f,0.f,0.f);};
inline void white(){apply_color(1.f,1.f,1.f);};

inline void clear_black(){clear_color(0.f,0.f,0.f);};
inline void clear_white(){clear_color(1.f,1.f,1.f);};

// clearing

inline void clear_color  (){glClear(GL_COLOR_BUFFER_BIT);};
inline void clear_depth  (){glClear(GL_DEPTH_BUFFER_BIT);};
inline void clear_accum  (){glClear(GL_ACCUM_BUFFER_BIT);};
inline void clear_stencil(){glClear(GL_STENCIL_BUFFER_BIT);};

inline void clear_depth(f32 a){glClearDepth(a);};

inline void clear(){glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_ACCUM_BUFFER_BIT|
	GL_STENCIL_BUFFER_BIT);};
inline void clear(bl a){if(a)clear();else glClear(GL_COLOR_BUFFER_BIT|GL_ACCUM_BUFFER_BIT|
	GL_STENCIL_BUFFER_BIT);};

// images
inline void bind  (video::image& a){a.bind();};
inline void unbind(){if(get_current_image())get_current_image()->unbind();};

// frame buffers
inline void bind      (video::buffer& a){a.bind();};
inline void deactivate(){if(get_current_buffer())get_current_buffer()->deactivate();};

// shaders
inline void stop(){if(get_current_shader())get_current_shader()->stop();};

// low level drawing

inline void begin(GLenum a){glBegin(a);};
inline void end  (){glEnd();};

inline void vert_2i(s32 x,s32 y){glVertex2i(x,y);};
inline void vert_3i(s32 x,s32 y,s32 z){glVertex3i(x,y,z);};
inline void vert_2f(f32 x,f32 y){glVertex2f(x,y);};
inline void vert_3f(f32 x,f32 y,f32 z){glVertex3f(x,y,z);};
inline void vert_3 (f32 x,f32 y,f32 z){vert_3f(x,y,z);};
inline void vert_2 (f32 x,f32 y){vert_2f(x,y);};
inline void vert   (f32 x,f32 y){vert_2(x,y);};

inline void normal (f32 x,f32 y,f32 z){glNormal3f(x,y,z);};
inline void norm   (f32 x,f32 y,f32 z){glNormal3f(x,y,z);};

inline void tex_1  (f32 x){glTexCoord1f(x);};
inline void tex_2  (f32 x,f32 y){glTexCoord2f(x,y);};
inline void tex_3  (f32 x,f32 y,f32 z){glTexCoord3f(x,y,z);};
inline void tex    (f32 x,f32 y){tex_2(x,y);};

// translation

inline void shift_x(f32 x){glTranslatef(x,0.f,0.f);};
inline void shift_y(f32 y){glTranslatef(0.f,y,0.f);};
inline void shift_z(f32 z){glTranslatef(0.f,0.f,z);};

inline void shift(f32 x,f32 y,f32 z){glTranslatef(x,y,z);};
inline void shift(f32 x,f32 y){glTranslatef(x,y,0.f);};
inline void shift(f32 x){glTranslatef(x,0.f,0.f);};

inline void shift(const math::vec3& v){glTranslatef(v.x,v.y,v.z);};
inline void shift(const math::vec2& v){glTranslatef(v.x,v.y,0.f);};

//inline void shift(const math::mob3& m){glTranslatef(m.pos.x,m.pos.y,m.pos.z);};
//inline void shift(const math::mob2& m){glTranslatef(m.pos.x,m.pos.y,0.f);};

inline void shift_x(const video::image& a){shift_x(a.get_width()); };
inline void shift_y(const video::image& a){shift_y(a.get_height());};

inline void shift_x(){shift_x(get_current_image()->get_width());};
inline void shift_y(){shift_y(get_current_image()->get_height());};

// rotation

inline void rotate_x(f32 d,f32 x){glRotatef(d,x,0.f,0.f);};
inline void rotate_x(f32 d){glRotatef(d,1.f,0.f,0.f);};
inline void rotate_y(f32 d,f32 y){glRotatef(d,0.f,y,0.f);};
inline void rotate_y(f32 d){glRotatef(d,0.f,1.f,0.f);};
inline void rotate_z(f32 d,f32 z){glRotatef(d,0.f,0.f,z);};
inline void rotate_z(f32 d){glRotatef(d,0.f,0.f,1.f);};

inline void rotate(f32 d,f32 x,f32 y,f32 z){glRotatef(d,x,y,z);};
inline void rotate(f32 x,f32 y,f32 z){rotate_x(x);rotate_y(y);rotate_z(z);};
inline void rotate(f32 x,f32 y){rotate_x(x);rotate_y(y);};
inline void rotate(f32 x){rotate_x(x);};

inline void rotate(const math::vec3& v){rotate_x(v.x);rotate_y(v.y);rotate_z(v.z);};
inline void rotate(const math::vec2& v){rotate_x(v.x);rotate_y(v.y);};

//inline void rotate(const math::mob3& m){rotate_x(m.dir.x);rotate_y(m.dir.y);rotate_z(m.dir.z);};
//inline void rotate(const math::mob2& m){rotate_x(m.dir.x);rotate_y(m.dir.y);};

// scaling

inline void scale_x(f32 x){glScalef(x,1.f,1.f);};
inline void scale_y(f32 y){glScalef(1.f,y,1.f);};
inline void scale_z(f32 z){glScalef(1.f,1.f,z);};

inline void scale(f32 x,f32 y,f32 z){glScalef(x,y,z);};
inline void scale(f32 x,f32 y){glScalef(x,y,1.f);};
inline void scale(f32 x){glScalef(x,1.f,1.f);};

inline void scale(const math::vec3& v){glScalef(v.x,v.y,v.z);};
inline void scale(const math::vec2& v){glScalef(v.x,v.y,1.f);};

//inline void scale(const math::mob3& m){glScalef(m.pos.x,m.pos.y,m.pos.z);};
//inline void scale(const math::mob2& m){glScalef(m.pos.x,m.pos.y,1.f);};

// high level drawing

inline void v_pos  (f32 x,f32 y){vx=x;vy=y;};
inline void v_pos_x(f32 x){vx=x;};
inline void v_pos_y(f32 y){vy=y;};

inline void v_shift  (f32 x,f32 y){vx+=x;vy+=y;};
inline void v_shift_x(f32 x){vx+=x;};
inline void v_shift_y(f32 y){vy+=y;};

inline void v_size  (f32 w,f32 h){vw=w;vh=h;};
inline void v_size_w(f32 w){vw=w;};
inline void v_size_h(f32 h){vh=h;};

inline void v_shift_x(const video::image& a){vx+=a.get_width();};
inline void v_shift_y(const video::image& a){vy+=a.get_height();};

inline void v_shift_x(){vx+=get_current_image()->get_width();};
inline void v_shift_y(){vy+=get_current_image()->get_height();};

inline void v_image(){vw=get_current_image()->get_width();vh=get_current_image()->get_height();};

inline void v_display(){vx=0.f;vy=0.f;vw=display::get_width();vh=display::get_height();};

inline void v_buffer(){vx=0.f;vy=0.f;
                       vw=get_current_buffer()->get_width();
                       vh=get_current_buffer()->get_height();};

inline void t_pos  (f32 x,f32 y){tx=x/get_current_image()->get_width();
                                 ty=y/get_current_image()->get_height();};
inline void t_pos_x(f32 x){tx=x/get_current_image()->get_width();};
inline void t_pos_y(f32 y){ty=y/get_current_image()->get_height();};

inline void t_shift  (f32 x,f32 y){tx+=x/get_current_image()->get_width();
                                   ty+=y/get_current_image()->get_height();};
inline void t_shift_x(f32 x){tx+=x/get_current_image()->get_width();};
inline void t_shift_y(f32 y){ty+=y/get_current_image()->get_height();};

inline void t_size  (f32 w,f32 h){tw=w/get_current_image()->get_width();
                                  th=h/get_current_image()->get_height();};
inline void t_size_x(f32 w){tw=w/get_current_image()->get_width();};
inline void t_size_y(f32 h){th=h/get_current_image()->get_height();};

inline void t_image(){tx=0.f;ty=0.f;tw=1.f;th=1.f;};

inline void t_vertex(){
	tx=vx/get_current_image()->get_width();
	ty=vy/get_current_image()->get_height();
	tw=vw/get_current_image()->get_width();
	th=vh/get_current_image()->get_height();
};

inline void t_flip_v(){ty+=th;th=-th;};
inline void t_flip_h(){tx+=tw;tw=-tw;};

inline void draw(bl texture){
	if(texture) {
		gl::tex(tx,   ty   );gl::vert(vx,   vy+vh);
		gl::tex(tx+tw,ty   );gl::vert(vx+vw,vy+vh);
		gl::tex(tx+tw,ty+th);gl::vert(vx+vw,vy   );
		gl::tex(tx,   ty+th);gl::vert(vx,   vy   );
	}else{
		gl::vert(vx,   vy+vh);
		gl::vert(vx+vw,vy+vh);
		gl::vert(vx+vw,vy   );
		gl::vert(vx,   vy   );}};

inline void draw(){draw(true);};

// rendering
inline void finish(){glFinish();};
inline void flush (){glFlush();};
inline void render(){video::render();};

/* opengl handling subsystem macro definitions */

// redefinitions
#define ACCUM                                 GL_ACCUM
#define ACCUM_ALPHA_BITS                      GL_ACCUM_ALPHA_BITS
#define ACCUM_BLUE_BITS                       GL_ACCUM_BLUE_BITS
#define ACCUM_BUFFER_BIT                      GL_ACCUM_BUFFER_BIT
#define ACCUM_CLEAR_VALUE                     GL_ACCUM_CLEAR_VALUE
#define ACCUM_GREEN_BITS                      GL_ACCUM_GREEN_BITS
#define ACCUM_RED_BITS                        GL_ACCUM_RED_BITS
#define ACTIVE_ATTRIBUTES                     GL_ACTIVE_ATTRIBUTES
#define ACTIVE_ATTRIBUTE_MAX_LENGTH           GL_ACTIVE_ATTRIBUTE_MAX_LENGTH
#define ACTIVE_TEXTURE                        GL_ACTIVE_TEXTURE
#define ACTIVE_UNIFORMS                       GL_ACTIVE_UNIFORMS
#define ACTIVE_UNIFORM_MAX_LENGTH             GL_ACTIVE_UNIFORM_MAX_LENGTH
#define ADD                                   GL_ADD
#define ALL_ATTRIB_BITS                       GL_ALL_ATTRIB_BITS
#define ALPHA                                 GL_ALPHA
#define ALPHA4                                GL_ALPHA4
#define ALPHA8                                GL_ALPHA8
#define ALPHA12                               GL_ALPHA12
#define ALPHA16                               GL_ALPHA16
#define ALPHA_BIAS                            GL_ALPHA_BIAS
#define ALPHA_BITS                            GL_ALPHA_BITS
#define ALPHA_SCALE                           GL_ALPHA_SCALE
#define ALPHA_TEST                            GL_ALPHA_TEST
#define ALPHA_TEST_FUNC                       GL_ALPHA_TEST_FUNC
#define ALPHA_TEST_REF                        GL_ALPHA_TEST_REF
#define ALWAYS                                GL_ALWAYS
#define AMBIENT                               GL_AMBIENT
#define AMBIENT_AND_DIFFUSE                   GL_AMBIENT_AND_DIFFUSE
#define AND                                   GL_AND
#define AND_INVERTED                          GL_AND_INVERTED
#define AND_REVERSE                           GL_AND_REVERSE
#define ARRAY_BUFFER                          GL_ARRAY_BUFFER
#define ARRAY_BUFFER_BINDING                  GL_ARRAY_BUFFER_BINDING
#define ATTACHED_SHADERS                      GL_ATTACHED_SHADERS
#define ATTRIB_STACK_DEPTH                    GL_ATTRIB_STACK_DEPTH
#define AUTO_NORMAL                           GL_AUTO_NORMAL
#define AUX0                                  GL_AUX0
#define AUX1                                  GL_AUX1
#define AUX2                                  GL_AUX2
#define AUX3                                  GL_AUX3
#define AUX_BUFFERS                           GL_AUX_BUFFERS
#define BACK                                  GL_BACK
#define BACK_LEFT                             GL_BACK_LEFT
#define BACK_RIGHT                            GL_BACK_RIGHT
#define BGR                                   GL_BGR
#define BGRA                                  GL_BGRA
#define BITMAP_TOKEN                          GL_BITMAP_TOKEN
#define BLEND                                 GL_BLEND
#define BLEND_DST                             GL_BLEND_DST
#define BLEND_EQUATION_ALPHA                  GL_BLEND_EQUATION_ALPHA
#define BLEND_EQUATION_RGB                    GL_BLEND_EQUATION_RGB
#define BLEND_SRC                             GL_BLEND_SRC
#define BLUE                                  GL_BLUE
#define BLUE_BIAS                             GL_BLUE_BIAS
#define BLUE_BITS                             GL_BLUE_BITS
#define BLUE_SCALE                            GL_BLUE_SCALE
#define BOOL_                                 GL_BOOL
#define BOOL_VEC2                             GL_BOOL_VEC2
#define BOOL_VEC3                             GL_BOOL_VEC3
#define BOOL_VEC4                             GL_BOOL_VEC4
#define BUFFER_ACCESS                         GL_BUFFER_ACCESS
#define BUFFER_MAPPED                         GL_BUFFER_MAPPED
#define BUFFER_MAP_POINTER                    GL_BUFFER_MAP_POINTER
#define BUFFER_SIZE                           GL_BUFFER_SIZE
#define BUFFER_USAGE                          GL_BUFFER_USAGE
#define BYTE_                                 GL_BYTE
#define C3F_V3F                               GL_C3F_V3F
#define C4F_N3F_V3F                           GL_C4F_N3F_V3F
#define C4UB_V2F                              GL_C4UB_V2F
#define C4UB_V3F                              GL_C4UB_V3F
#define CCW                                   GL_CCW
#define CLAMP                                 GL_CLAMP
#define CLAMP_TO_BORDER                       GL_CLAMP_TO_BORDER
#define CLEAR                                 GL_CLEAR
#define CLIENT_ALL_ATTRIB_BITS                GL_CLIENT_ALL_ATTRIB_BITS
#define CLIENT_ATTRIB_STACK_DEPTH             GL_CLIENT_ATTRIB_STACK_DEPTH
#define CLIENT_PIXEL_STORE_BIT                GL_CLIENT_PIXEL_STORE_BIT
#define CLIENT_VERTEX_ARRAY_BIT               GL_CLIENT_VERTEX_ARRAY_BIT
#define CLIP_PLANE0                           GL_CLIP_PLANE0
#define CLIP_PLANE1                           GL_CLIP_PLANE1
#define CLIP_PLANE2                           GL_CLIP_PLANE2
#define CLIP_PLANE3                           GL_CLIP_PLANE3
#define CLIP_PLANE4                           GL_CLIP_PLANE4
#define CLIP_PLANE5                           GL_CLIP_PLANE5
#define COEFF                                 GL_COEFF
#define COLOR_                                GL_COLOR
#define COLOR_ARRAY                           GL_COLOR_ARRAY
#define COLOR_ARRAY_BUFFER_BINDING            GL_COLOR_ARRAY_BUFFER_BINDING
#define COLOR_ARRAY_POINTER                   GL_COLOR_ARRAY_POINTER
#define COLOR_ARRAY_SIZE                      GL_COLOR_ARRAY_SIZE
#define COLOR_ARRAY_STRIDE                    GL_COLOR_ARRAY_STRIDE
#define COLOR_ARRAY_TYPE                      GL_COLOR_ARRAY_TYPE
#define COLOR_ATTACHMENT0                     GL_COLOR_ATTACHMENT0
#define COLOR_ATTACHMENT0_ARB                 GL_COLOR_ATTACHMENT0_ARB
#define COLOR_ATTACHMENT0_EXT                 GL_COLOR_ATTACHMENT0_EXT
#define COLOR_BUFFER_BIT                      GL_COLOR_BUFFER_BIT
#define COLOR_CLEAR_VALUE                     GL_COLOR_CLEAR_VALUE
#define COLOR_INDEX                           GL_COLOR_INDEX
#define COLOR_INDEX1_EXT                      GL_COLOR_INDEX1_EXT
#define COLOR_INDEX2_EXT                      GL_COLOR_INDEX2_EXT
#define COLOR_INDEX4_EXT                      GL_COLOR_INDEX4_EXT
#define COLOR_INDEX8_EXT                      GL_COLOR_INDEX8_EXT
#define COLOR_INDEX12_EXT                     GL_COLOR_INDEX12_EXT
#define COLOR_INDEX16_EXT                     GL_COLOR_INDEX16_EXT
#define COLOR_INDEXES                         GL_COLOR_INDEXES
#define COLOR_LOGIC_OP                        GL_COLOR_LOGIC_OP
#define COLOR_MATERIAL                        GL_COLOR_MATERIAL
#define COLOR_MATERIAL_FACE                   GL_COLOR_MATERIAL_FACE
#define COLOR_MATERIAL_PARAMETER              GL_COLOR_MATERIAL_PARAMETER
#define COLOR_WRITEMASK                       GL_COLOR_WRITEMASK
#define COMPILE                               GL_COMPILE
#define COMPILE_AND_EXECUTE                   GL_COMPILE_AND_EXECUTE
#define COMPILE_STATUS                        GL_COMPILE_STATUS
#define COMPRESSED_RGB                        GL_COMPRESSED_RGB
#define COMPRESSED_RGBA                       GL_COMPRESSED_RGBA
#define COMPRESSED_TEXTURE_FORMATS            GL_COMPRESSED_TEXTURE_FORMATS
#define CONSTANT_ATTENUATION                  GL_CONSTANT_ATTENUATION
#define COORD_REPLACE                         GL_COORD_REPLACE
#define COPY                                  GL_COPY
#define COPY_INVERTED                         GL_COPY_INVERTED
#define COPY_PIXEL_TOKEN                      GL_COPY_PIXEL_TOKEN
#define CULL_FACE                             GL_CULL_FACE
#define CULL_FACE_MODE                        GL_CULL_FACE_MODE
#define CURRENT_BIT                           GL_CURRENT_BIT
#define CURRENT_COLOR                         GL_CURRENT_COLOR
#define CURRENT_INDEX                         GL_CURRENT_INDEX
#define CURRENT_NORMAL                        GL_CURRENT_NORMAL
#define CURRENT_PROGRAM                       GL_CURRENT_PROGRAM
#define CURRENT_RASTER_COLOR                  GL_CURRENT_RASTER_COLOR
#define CURRENT_RASTER_DISTANCE               GL_CURRENT_RASTER_DISTANCE
#define CURRENT_RASTER_INDEX                  GL_CURRENT_RASTER_INDEX
#define CURRENT_RASTER_POSITION               GL_CURRENT_RASTER_POSITION
#define CURRENT_RASTER_POSITION_VALID         GL_CURRENT_RASTER_POSITION_VALID
#define CURRENT_RASTER_TEXTURE_COORDS         GL_CURRENT_RASTER_TEXTURE_COORDS
#define CURRENT_TEXTURE_COORDS                GL_CURRENT_TEXTURE_COORDS
#define CURRENT_VERTEX_ATTRIB                 GL_CURRENT_VERTEX_ATTRIB
#define CW                                    GL_CW
#define DECAL                                 GL_DECAL
#define DECR                                  GL_DECR
#define DELETE_STATUS                         GL_DELETE_STATUS
#define DEPTH                                 GL_DEPTH
#define DEPTH_ATTACHMENT                      GL_DEPTH_ATTACHMENT
#define DEPTH_BIAS                            GL_DEPTH_BIAS
#define DEPTH_BITS                            GL_DEPTH_BITS
#define DEPTH_BUFFER_BIT                      GL_DEPTH_BUFFER_BIT
#define DEPTH_CLEAR_VALUE                     GL_DEPTH_CLEAR_VALUE
#define DEPTH_COMPONENT                       GL_DEPTH_COMPONENT
#define DEPTH_FUNC                            GL_DEPTH_FUNC
#define DEPTH_RANGE                           GL_DEPTH_RANGE
#define DEPTH_SCALE                           GL_DEPTH_SCALE
#define DEPTH_TEST                            GL_DEPTH_TEST
#define DEPTH_WRITEMASK                       GL_DEPTH_WRITEMASK
#define DIFFUSE                               GL_DIFFUSE
#define DITHER                                GL_DITHER
#define DONT_CARE                             GL_DONT_CARE
#define DOUBLE                                GL_DOUBLE
#define DOUBLEBUFFER                          GL_DOUBLEBUFFER
#define DRAW_BUFFER                           GL_DRAW_BUFFER
#define DRAW_BUFFER0                          GL_DRAW_BUFFER0
#define DRAW_BUFFER1                          GL_DRAW_BUFFER1
#define DRAW_BUFFER2                          GL_DRAW_BUFFER2
#define DRAW_BUFFER3                          GL_DRAW_BUFFER3
#define DRAW_BUFFER4                          GL_DRAW_BUFFER4
#define DRAW_BUFFER5                          GL_DRAW_BUFFER5
#define DRAW_BUFFER6                          GL_DRAW_BUFFER6
#define DRAW_BUFFER7                          GL_DRAW_BUFFER7
#define DRAW_BUFFER8                          GL_DRAW_BUFFER8
#define DRAW_BUFFER9                          GL_DRAW_BUFFER9
#define DRAW_BUFFER10                         GL_DRAW_BUFFER10
#define DRAW_BUFFER11                         GL_DRAW_BUFFER11
#define DRAW_BUFFER12                         GL_DRAW_BUFFER12
#define DRAW_BUFFER13                         GL_DRAW_BUFFER13
#define DRAW_BUFFER14                         GL_DRAW_BUFFER14
#define DRAW_BUFFER15                         GL_DRAW_BUFFER15
#define DRAW_PIXEL_TOKEN                      GL_DRAW_PIXEL_TOKEN
#define DST_ALPHA                             GL_DST_ALPHA
#define DST_COLOR                             GL_DST_COLOR
#define DYNAMIC_COPY                          GL_DYNAMIC_COPY
#define DYNAMIC_DRAW                          GL_DYNAMIC_DRAW
#define DYNAMIC_READ                          GL_DYNAMIC_READ
#define EDGE_FLAG                             GL_EDGE_FLAG
#define EDGE_FLAG_ARRAY                       GL_EDGE_FLAG_ARRAY
#define EDGE_FLAG_ARRAY_BUFFER_BINDING        GL_EDGE_FLAG_ARRAY_BUFFER_BINDING
#define EDGE_FLAG_ARRAY_POINTER               GL_EDGE_FLAG_ARRAY_POINTER
#define EDGE_FLAG_ARRAY_STRIDE                GL_EDGE_FLAG_ARRAY_STRIDE
#define ELEMENT_ARRAY_BUFFER                  GL_ELEMENT_ARRAY_BUFFER
#define ELEMENT_ARRAY_BUFFER_BINDING          GL_ELEMENT_ARRAY_BUFFER_BINDING
#define EMISSION                              GL_EMISSION
#define ENABLE_BIT                            GL_ENABLE_BIT
#define EQUAL                                 GL_EQUAL
#define EQUIV                                 GL_EQUIV
#define EVAL_BIT                              GL_EVAL_BIT
#define EXP                                   GL_EXP
#define EXP2                                  GL_EXP2
#define EXTENSIONS                            GL_EXTENSIONS
#define EYE_LINEAR                            GL_EYE_LINEAR
#define EYE_PLANE                             GL_EYE_PLANE
#define FASTEST                               GL_FASTEST
#define FEEDBACK                              GL_FEEDBACK
#define FEEDBACK_BUFFER_POINTER               GL_FEEDBACK_BUFFER_POINTER
#define FEEDBACK_BUFFER_SIZE                  GL_FEEDBACK_BUFFER_SIZE
#define FEEDBACK_BUFFER_TYPE                  GL_FEEDBACK_BUFFER_TYPE
#define FILL                                  GL_FILL
#define FLAT                                  GL_FLAT
#define FLOAT                                 GL_FLOAT
#define FLOAT_MAT2                            GL_FLOAT_MAT2
#define FLOAT_MAT3                            GL_FLOAT_MAT3
#define FLOAT_MAT4                            GL_FLOAT_MAT4
#define FLOAT_VEC2                            GL_FLOAT_VEC2
#define FLOAT_VEC3                            GL_FLOAT_VEC3
#define FLOAT_VEC4                            GL_FLOAT_VEC4
#define FOG                                   GL_FOG
#define FOG_BIT                               GL_FOG_BIT
#define FOG_COLOR                             GL_FOG_COLOR
#define FOG_COORDINATE_ARRAY_BUFFER_BINDING   GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING
#define FOG_DENSITY                           GL_FOG_DENSITY
#define FOG_END                               GL_FOG_END
#define FOG_HINT                              GL_FOG_HINT
#define FOG_INDEX                             GL_FOG_INDEX
#define FOG_MODE                              GL_FOG_MODE
#define FOG_START                             GL_FOG_START
#define FRAMEBUFFER                           GL_FRAMEBUFFER
#define FRAMEBUFFER_ARB                       GL_FRAMEBUFFER_ARB
#define FRAMEBUFFER_EXT                       GL_FRAMEBUFFER_EXT
#define FRAGMENT_SHADER                       GL_FRAGMENT_SHADER
#define FRAGMENT_SHADER_ARB                   GL_FRAGMENT_SHADER_ARB
#define FRAGMENT_SHADER_DERIVATIVE_HINT       GL_FRAGMENT_SHADER_DERIVATIVE_HINT
#define FRAGMENT_SHADER_DERIVATIVE_HINT       GL_FRAGMENT_SHADER_DERIVATIVE_HINT
#define FRONT                                 GL_FRONT
#define FRONT_AND_BACK                        GL_FRONT_AND_BACK
#define FRONT_FACE                            GL_FRONT_FACE
#define FRONT_LEFT                            GL_FRONT_LEFT
#define FRONT_RIGHT                           GL_FRONT_RIGHT
#define GENERATE_MIPMAP_HINT                  GL_GENERATE_MIPMAP_HINT
#define GEQUAL                                GL_GEQUAL
#define GREATER                               GL_GREATER
#define GREEN                                 GL_GREEN
#define GREEN_BIAS                            GL_GREEN_BIAS
#define GREEN_BITS                            GL_GREEN_BITS
#define GREEN_SCALE                           GL_GREEN_SCALE
#define HINT_BIT                              GL_HINT_BIT
#define INCR                                  GL_INCR
#define INDEX_ARRAY                           GL_INDEX_ARRAY
#define INDEX_ARRAY_BUFFER_BINDING            GL_INDEX_ARRAY_BUFFER_BINDING
#define INDEX_ARRAY_POINTER                   GL_INDEX_ARRAY_POINTER
#define INDEX_ARRAY_STRIDE                    GL_INDEX_ARRAY_STRIDE
#define INDEX_ARRAY_TYPE                      GL_INDEX_ARRAY_TYPE
#define INDEX_BITS                            GL_INDEX_BITS
#define INDEX_CLEAR_VALUE                     GL_INDEX_CLEAR_VALUE
#define INDEX_LOGIC_OP                        GL_INDEX_LOGIC_OP
#define INDEX_MODE                            GL_INDEX_MODE
#define INDEX_OFFSET                          GL_INDEX_OFFSET
#define INDEX_SHIFT                           GL_INDEX_SHIFT
#define INDEX_WRITEMASK                       GL_INDEX_WRITEMASK
#define INFO_LOG_LENGTH                       GL_INFO_LOG_LENGTH
#define INT_                                  GL_INT
#define INTENSITY                             GL_INTENSITY
#define INTENSITY4                            GL_INTENSITY4
#define INTENSITY8                            GL_INTENSITY8
#define INTENSITY12                           GL_INTENSITY12
#define INTENSITY16                           GL_INTENSITY16
#define INT_VEC2                              GL_INT_VEC2
#define INT_VEC3                              GL_INT_VEC3
#define INT_VEC4                              GL_INT_VEC4
#define INVALID_ENUM                          GL_INVALID_ENUM
#define INVALID_OPERATION                     GL_INVALID_OPERATION
#define INVALID_VALUE                         GL_INVALID_VALUE
#define INVERT                                GL_INVERT
#define KEEP                                  GL_KEEP
#define LEFT_                                 GL_LEFT
#define LEQUAL                                GL_LEQUAL
#define LESS                                  GL_LESS
#define LIGHT0                                GL_LIGHT0
#define LIGHT1                                GL_LIGHT1
#define LIGHT2                                GL_LIGHT2
#define LIGHT3                                GL_LIGHT3
#define LIGHT4                                GL_LIGHT4
#define LIGHT5                                GL_LIGHT5
#define LIGHT6                                GL_LIGHT6
#define LIGHT7                                GL_LIGHT7
#define LIGHTING                              GL_LIGHTING
#define LIGHTING_BIT                          GL_LIGHTING_BIT
#define LIGHT_MODEL_AMBIENT                   GL_LIGHT_MODEL_AMBIENT
#define LIGHT_MODEL_LOCAL_VIEWER              GL_LIGHT_MODEL_LOCAL_VIEWER
#define LIGHT_MODEL_TWO_SIDE                  GL_LIGHT_MODEL_TWO_SIDE
#define LINE                                  GL_LINE
#define LINEAR                                GL_LINEAR
#define LINEAR_ATTENUATION                    GL_LINEAR_ATTENUATION
#define LINEAR_MIPMAP_LINEAR                  GL_LINEAR_MIPMAP_LINEAR
#define LINEAR_MIPMAP_NEAREST                 GL_LINEAR_MIPMAP_NEAREST
#define LINES                                 GL_LINES
#define LINE_BIT                              GL_LINE_BIT
#define LINE_LOOP                             GL_LINE_LOOP
#define LINE_RESET_TOKEN                      GL_LINE_RESET_TOKEN
#define LINE_SMOOTH                           GL_LINE_SMOOTH
#define LINE_SMOOTH_HINT                      GL_LINE_SMOOTH_HINT
#define LINE_STIPPLE                          GL_LINE_STIPPLE
#define LINE_STIPPLE_PATTERN                  GL_LINE_STIPPLE_PATTERN
#define LINE_STIPPLE_REPEAT                   GL_LINE_STIPPLE_REPEAT
#define LINE_STRIP                            GL_LINE_STRIP
#define LINE_TOKEN                            GL_LINE_TOKEN
#define LINE_WIDTH                            GL_LINE_WIDTH
#define LINE_WIDTH_GRANULARITY                GL_LINE_WIDTH_GRANULARITY
#define LINE_WIDTH_RANGE                      GL_LINE_WIDTH_RANGE
#define LINK_STATUS                           GL_LINK_STATUS
#define LIST_BASE                             GL_LIST_BASE
#define LIST_BIT                              GL_LIST_BIT
#define LIST_INDEX                            GL_LIST_INDEX
#define LIST_MODE                             GL_LIST_MODE
#define LOAD                                  GL_LOAD
#define LOGIC_OP                              GL_LOGIC_OP
#define LOGIC_OP_MODE                         GL_LOGIC_OP_MODE
#define LOWER_LEFT                            GL_LOWER_LEFT
#define LUMINANCE                             GL_LUMINANCE
#define LUMINANCE4                            GL_LUMINANCE4
#define LUMINANCE4_ALPHA4                     GL_LUMINANCE4_ALPHA4
#define LUMINANCE6_ALPHA2                     GL_LUMINANCE6_ALPHA2
#define LUMINANCE8                            GL_LUMINANCE8
#define LUMINANCE8_ALPHA8                     GL_LUMINANCE8_ALPHA8
#define LUMINANCE12                           GL_LUMINANCE12
#define LUMINANCE12_ALPHA4                    GL_LUMINANCE12_ALPHA4
#define LUMINANCE12_ALPHA12                   GL_LUMINANCE12_ALPHA12
#define LUMINANCE16                           GL_LUMINANCE16
#define LUMINANCE16_ALPHA16                   GL_LUMINANCE16_ALPHA16
#define LUMINANCE_ALPHA                       GL_LUMINANCE_ALPHA
#define MAP1_COLOR_4                          GL_MAP1_COLOR_4
#define MAP1_GRID_DOMAIN                      GL_MAP1_GRID_DOMAIN
#define MAP1_GRID_SEGMENTS                    GL_MAP1_GRID_SEGMENTS
#define MAP1_INDEX                            GL_MAP1_INDEX
#define MAP1_NORMAL                           GL_MAP1_NORMAL
#define MAP1_TEXTURE_COORD_1                  GL_MAP1_TEXTURE_COORD_1
#define MAP1_TEXTURE_COORD_2                  GL_MAP1_TEXTURE_COORD_2
#define MAP1_TEXTURE_COORD_3                  GL_MAP1_TEXTURE_COORD_3
#define MAP1_TEXTURE_COORD_4                  GL_MAP1_TEXTURE_COORD_4
#define MAP1_VERTEX_3                         GL_MAP1_VERTEX_3
#define MAP1_VERTEX_4                         GL_MAP1_VERTEX_4
#define MAP2_COLOR_4                          GL_MAP2_COLOR_4
#define MAP2_GRID_DOMAIN                      GL_MAP2_GRID_DOMAIN
#define MAP2_GRID_SEGMENTS                    GL_MAP2_GRID_SEGMENTS
#define MAP2_INDEX                            GL_MAP2_INDEX
#define MAP2_NORMAL                           GL_MAP2_NORMAL
#define MAP2_TEXTURE_COORD_1                  GL_MAP2_TEXTURE_COORD_1
#define MAP2_TEXTURE_COORD_2                  GL_MAP2_TEXTURE_COORD_2
#define MAP2_TEXTURE_COORD_3                  GL_MAP2_TEXTURE_COORD_3
#define MAP2_TEXTURE_COORD_4                  GL_MAP2_TEXTURE_COORD_4
#define MAP2_VERTEX_3                         GL_MAP2_VERTEX_3
#define MAP2_VERTEX_4                         GL_MAP2_VERTEX_4
#define MAP_COLOR                             GL_MAP_COLOR
#define MAP_STENCIL                           GL_MAP_STENCIL
#define MATRIX_MODE                           GL_MATRIX_MODE
#define MAX_ATTRIB_STACK_DEPTH                GL_MAX_ATTRIB_STACK_DEPTH
#define MAX_CLIENT_ATTRIB_STACK_DEPTH         GL_MAX_CLIENT_ATTRIB_STACK_DEPTH
#define MAX_CLIP_PLANES                       GL_MAX_CLIP_PLANES
#define MAX_COMBINED_TEXTURE_IMAGE_UNITS      GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
#define MAX_CUBE_MAP_TEXTURE_SIZE             GL_MAX_CUBE_MAP_TEXTURE_SIZE
#define MAX_DRAW_BUFFERS                      GL_MAX_DRAW_BUFFERS
#define MAX_EVAL_ORDER                        GL_MAX_EVAL_ORDER
#define MAX_FRAGMENT_UNIFORM_COMPONENTS       GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
#define MAX_FRAGMENT_UNIFORM_COMPONENTS       GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
#define MAX_LIGHTS                            GL_MAX_LIGHTS
#define MAX_LIST_NESTING                      GL_MAX_LIST_NESTING
#define MAX_MODELVIEW_STACK_DEPTH             GL_MAX_MODELVIEW_STACK_DEPTH
#define MAX_NAME_STACK_DEPTH                  GL_MAX_NAME_STACK_DEPTH
#define MAX_PIXEL_MAP_TABLE                   GL_MAX_PIXEL_MAP_TABLE
#define MAX_PROJECTION_STACK_DEPTH            GL_MAX_PROJECTION_STACK_DEPTH
#define MAX_TEXTURE_COORDS                    GL_MAX_TEXTURE_COORDS
#define MAX_TEXTURE_IMAGE_UNITS               GL_MAX_TEXTURE_IMAGE_UNITS
#define MAX_TEXTURE_SIZE                      GL_MAX_TEXTURE_SIZE
#define MAX_TEXTURE_STACK_DEPTH               GL_MAX_TEXTURE_STACK_DEPTH
#define MAX_VARYING_FLOATS                    GL_MAX_VARYING_FLOATS
#define MAX_VERTEX_ATTRIBS                    GL_MAX_VERTEX_ATTRIBS
#define MAX_VERTEX_TEXTURE_IMAGE_UNITS        GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
#define MAX_VERTEX_UNIFORM_COMPONENTS         GL_MAX_VERTEX_UNIFORM_COMPONENTS
#define MAX_VIEWPORT_DIMS                     GL_MAX_VIEWPORT_DIMS
#define MODELVIEW                             GL_MODELVIEW
#define MODELVIEW_MATRIX                      GL_MODELVIEW_MATRIX
#define MODELVIEW_STACK_DEPTH                 GL_MODELVIEW_STACK_DEPTH
#define MODULATE                              GL_MODULATE
#define MULT                                  GL_MULT
#define MULTISAMPLE                           GL_MULTISAMPLE
#define N3F_V3F                               GL_N3F_V3F
#define NAME_STACK_DEPTH                      GL_NAME_STACK_DEPTH
#define NAND                                  GL_NAND
#define NEAREST                               GL_NEAREST
#define NEAREST_MIPMAP_LINEAR                 GL_NEAREST_MIPMAP_LINEAR
#define NEAREST_MIPMAP_NEAREST                GL_NEAREST_MIPMAP_NEAREST
#define NEVER                                 GL_NEVER
#define NICEST                                GL_NICEST
#define NONE                                  GL_NONE
#define NOOP                                  GL_NOOP
#define NOR                                   GL_NOR
#define NORMALIZE                             GL_NORMALIZE
#define NORMAL_ARRAY                          GL_NORMAL_ARRAY
#define NORMAL_ARRAY_BUFFER_BINDING           GL_NORMAL_ARRAY_BUFFER_BINDING
#define NORMAL_ARRAY_POINTER                  GL_NORMAL_ARRAY_POINTER
#define NORMAL_ARRAY_STRIDE                   GL_NORMAL_ARRAY_STRIDE
#define NORMAL_ARRAY_TYPE                     GL_NORMAL_ARRAY_TYPE
#define NOTEQUAL                              GL_NOTEQUAL
#define NUM_COMPRESSED_TEXTURE_FORMATS        GL_NUM_COMPRESSED_TEXTURE_FORMATS
#define OBJECT_INFO_LOG_LENGTH_ARB            GL_OBJECT_INFO_LOG_LENGTH_ARB
#define OBJECT_LINEAR                         GL_OBJECT_LINEAR
#define OBJECT_PLANE                          GL_OBJECT_PLANE
#define ONE                                   GL_ONE
#define ONE_MINUS_DST_ALPHA                   GL_ONE_MINUS_DST_ALPHA
#define ONE_MINUS_DST_COLOR                   GL_ONE_MINUS_DST_COLOR
#define ONE_MINUS_SRC_ALPHA                   GL_ONE_MINUS_SRC_ALPHA
#define ONE_MINUS_SRC_COLOR                   GL_ONE_MINUS_SRC_COLOR
#define OR                                    GL_OR
#define ORDER                                 GL_ORDER
#define OR_INVERTED                           GL_OR_INVERTED
#define OR_REVERSE                            GL_OR_REVERSE
#define OUT_OF_MEMORY                         GL_OUT_OF_MEMORY
#define PACK_ALIGNMENT                        GL_PACK_ALIGNMENT
#define PACK_LSB_FIRST                        GL_PACK_LSB_FIRST
#define PACK_ROW_LENGTH                       GL_PACK_ROW_LENGTH
#define PACK_SKIP_PIXELS                      GL_PACK_SKIP_PIXELS
#define PACK_SKIP_ROWS                        GL_PACK_SKIP_ROWS
#define PACK_SWAP_BYTES                       GL_PACK_SWAP_BYTES
#define PASS_THROUGH_TOKEN                    GL_PASS_THROUGH_TOKEN
#define PERSPECTIVE_CORRECTION_HINT           GL_PERSPECTIVE_CORRECTION_HINT
#define PIXEL_MAP_A_TO_A                      GL_PIXEL_MAP_A_TO_A
#define PIXEL_MAP_A_TO_A_SIZE                 GL_PIXEL_MAP_A_TO_A_SIZE
#define PIXEL_MAP_B_TO_B                      GL_PIXEL_MAP_B_TO_B
#define PIXEL_MAP_B_TO_B_SIZE                 GL_PIXEL_MAP_B_TO_B_SIZE
#define PIXEL_MAP_G_TO_G                      GL_PIXEL_MAP_G_TO_G
#define PIXEL_MAP_G_TO_G_SIZE                 GL_PIXEL_MAP_G_TO_G_SIZE
#define PIXEL_MAP_I_TO_A                      GL_PIXEL_MAP_I_TO_A
#define PIXEL_MAP_I_TO_A_SIZE                 GL_PIXEL_MAP_I_TO_A_SIZE
#define PIXEL_MAP_I_TO_B                      GL_PIXEL_MAP_I_TO_B
#define PIXEL_MAP_I_TO_B_SIZE                 GL_PIXEL_MAP_I_TO_B_SIZE
#define PIXEL_MAP_I_TO_G                      GL_PIXEL_MAP_I_TO_G
#define PIXEL_MAP_I_TO_G_SIZE                 GL_PIXEL_MAP_I_TO_G_SIZE
#define PIXEL_MAP_I_TO_I                      GL_PIXEL_MAP_I_TO_I
#define PIXEL_MAP_I_TO_I_SIZE                 GL_PIXEL_MAP_I_TO_I_SIZE
#define PIXEL_MAP_I_TO_R                      GL_PIXEL_MAP_I_TO_R
#define PIXEL_MAP_I_TO_R_SIZE                 GL_PIXEL_MAP_I_TO_R_SIZE
#define PIXEL_MAP_R_TO_R                      GL_PIXEL_MAP_R_TO_R
#define PIXEL_MAP_R_TO_R_SIZE                 GL_PIXEL_MAP_R_TO_R_SIZE
#define PIXEL_MAP_S_TO_S                      GL_PIXEL_MAP_S_TO_S
#define PIXEL_MAP_S_TO_S_SIZE                 GL_PIXEL_MAP_S_TO_S_SIZE
#define PIXEL_MODE_BIT                        GL_PIXEL_MODE_BIT
#define POINT_                                GL_POINT
#define POINTS                                GL_POINTS
#define POINT_BIT                             GL_POINT_BIT
#define POINT_SIZE                            GL_POINT_SIZE
#define POINT_SIZE_GRANULARITY                GL_POINT_SIZE_GRANULARITY
#define POINT_SIZE_RANGE                      GL_POINT_SIZE_RANGE
#define POINT_SMOOTH                          GL_POINT_SMOOTH
#define POINT_SMOOTH_HINT                     GL_POINT_SMOOTH_HINT
#define POINT_SPRITE                          GL_POINT_SPRITE
#define POINT_SPRITE_COORD_ORIGIN             GL_POINT_SPRITE_COORD_ORIGIN
#define POINT_TOKEN                           GL_POINT_TOKEN
#define POLYGON                               GL_POLYGON
#define POLYGON_BIT                           GL_POLYGON_BIT
#define POLYGON_MODE                          GL_POLYGON_MODE
#define POLYGON_OFFSET_FACTOR                 GL_POLYGON_OFFSET_FACTOR
#define POLYGON_OFFSET_FILL                   GL_POLYGON_OFFSET_FILL
#define POLYGON_OFFSET_LINE                   GL_POLYGON_OFFSET_LINE
#define POLYGON_OFFSET_POINT                  GL_POLYGON_OFFSET_POINT
#define POLYGON_OFFSET_UNITS                  GL_POLYGON_OFFSET_UNITS
#define POLYGON_SMOOTH                        GL_POLYGON_SMOOTH
#define POLYGON_SMOOTH_HINT                   GL_POLYGON_SMOOTH_HINT
#define POLYGON_STIPPLE                       GL_POLYGON_STIPPLE
#define POLYGON_STIPPLE_BIT                   GL_POLYGON_STIPPLE_BIT
#define POLYGON_TOKEN                         GL_POLYGON_TOKEN
#define POSITION                              GL_POSITION
#define PROJECTION                            GL_PROJECTION
#define PROJECTION_MATRIX                     GL_PROJECTION_MATRIX
#define PROJECTION_STACK_DEPTH                GL_PROJECTION_STACK_DEPTH
#define PROXY_TEXTURE_1D                      GL_PROXY_TEXTURE_1D
#define PROXY_TEXTURE_2D                      GL_PROXY_TEXTURE_2D
#define PROXY_TEXTURE_CUBE_MAP                GL_PROXY_TEXTURE_CUBE_MAP
#define QUADRATIC_ATTENUATION                 GL_QUADRATIC_ATTENUATION
#define QUADS                                 GL_QUADS
#define QUAD_STRIP                            GL_QUAD_STRIP
#define R3_G3_B2                              GL_R3_G3_B2
#define READ_BUFFER                           GL_READ_BUFFER
#define READ_ONLY                             GL_READ_ONLY
#define READ_WRITE                            GL_READ_WRITE
#define RED                                   GL_RED
#define RED_BIAS                              GL_RED_BIAS
#define RED_BITS                              GL_RED_BITS
#define RED_SCALE                             GL_RED_SCALE
#define RENDER                                GL_RENDER
#define RENDERBUFFER                          GL_RENDERBUFFER
#define RENDERBUFFER_ARB                      GL_RENDERBUFFER_ARB
#define RENDERBUFFER_EXT                      GL_RENDERBUFFER_EXT
#define RENDERER                              GL_RENDERER
#define RENDER_MODE                           GL_RENDER_MODE
#define REPEAT                                GL_REPEAT
#define REPLACE                               GL_REPLACE
#define RETURN                                GL_RETURN
#define RGB_                                  GL_RGB
#define RGB4                                  GL_RGB4
#define RGB5                                  GL_RGB5
#define RGB5_A1                               GL_RGB5_A1
#define RGB8                                  GL_RGB8
#define RGB10                                 GL_RGB10
#define RGB10_A2                              GL_RGB10_A2
#define RGB12                                 GL_RGB12
#define RGB16                                 GL_RGB16
#define RGBA                                  GL_RGBA
#define RGBA2                                 GL_RGBA2
#define RGBA4                                 GL_RGBA4
#define RGBA8                                 GL_RGBA8
#define RGBA12                                GL_RGBA12
#define RGBA16                                GL_RGBA16
#define RGBA_MODE                             GL_RGBA_MODE
#define RIGHT_                                GL_RIGHT
#define SAMPLER_1D                            GL_SAMPLER_1D
#define SAMPLER_1D_SHADOW                     GL_SAMPLER_1D_SHADOW
#define SAMPLER_2D                            GL_SAMPLER_2D
#define SAMPLER_2D_SHADOW                     GL_SAMPLER_2D_SHADOW
#define SAMPLER_3D                            GL_SAMPLER_3D
#define SAMPLER_CUBE                          GL_SAMPLER_CUBE
#define SAMPLES                               GL_SAMPLES
#define SAMPLE_ALPHA_TO_COVERAGE              GL_SAMPLE_ALPHA_TO_COVERAGE
#define SAMPLE_ALPHA_TO_ONE                   GL_SAMPLE_ALPHA_TO_ONE
#define SAMPLE_BUFFERS                        GL_SAMPLE_BUFFERS
#define SAMPLE_COVERAGE                       GL_SAMPLE_COVERAGE
#define SAMPLE_COVERAGE_INVERT                GL_SAMPLE_COVERAGE_INVERT
#define SAMPLE_COVERAGE_VALUE                 GL_SAMPLE_COVERAGE_VALUE
#define SCISSOR_BIT                           GL_SCISSOR_BIT
#define SCISSOR_BOX                           GL_SCISSOR_BOX
#define SCISSOR_TEST                          GL_SCISSOR_TEST
#define SECONDARY_COLOR_ARRAY_BUFFER_BINDING  GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING
#define SELECT                                GL_SELECT
#define SELECTION_BUFFER_POINTER              GL_SELECTION_BUFFER_POINTER
#define SELECTION_BUFFER_SIZE                 GL_SELECTION_BUFFER_SIZE
#define SET                                   GL_SET
#define SHADER_SOURCE_LENGTH                  GL_SHADER_SOURCE_LENGTH
#define SHADER_TYPE                           GL_SHADER_TYPE
#define SHADE_MODEL                           GL_SHADE_MODEL
#define SHADING_LANGUAGE_VERSION              GL_SHADING_LANGUAGE_VERSION
#define SHININESS                             GL_SHININESS
#define SHORT                                 GL_SHORT
#define SMOOTH                                GL_SMOOTH
#define SPECULAR                              GL_SPECULAR
#define SPHERE_MAP                            GL_SPHERE_MAP
#define SPOT_CUTOFF                           GL_SPOT_CUTOFF
#define SPOT_DIRECTION                        GL_SPOT_DIRECTION
#define SPOT_EXPONENT                         GL_SPOT_EXPONENT
#define SRC_ALPHA                             GL_SRC_ALPHA
#define SRC_ALPHA_SATURATE                    GL_SRC_ALPHA_SATURATE
#define SRC_COLOR                             GL_SRC_COLOR
#define STACK_OVERFLOW                        GL_STACK_OVERFLOW
#define STACK_UNDERFLOW                       GL_STACK_UNDERFLOW
#define STATIC_COPY                           GL_STATIC_COPY
#define STATIC_DRAW                           GL_STATIC_DRAW
#define STATIC_READ                           GL_STATIC_READ
#define STENCIL                               GL_STENCIL
#define STENCIL_BACK_FAIL                     GL_STENCIL_BACK_FAIL
#define STENCIL_BACK_FUNC                     GL_STENCIL_BACK_FUNC
#define STENCIL_BACK_PASS_DEPTH_FAIL          GL_STENCIL_BACK_PASS_DEPTH_FAIL
#define STENCIL_BACK_PASS_DEPTH_PASS          GL_STENCIL_BACK_PASS_DEPTH_PASS
#define STENCIL_BACK_REF                      GL_STENCIL_BACK_REF
#define STENCIL_BACK_VALUE_MASK               GL_STENCIL_BACK_VALUE_MASK
#define STENCIL_BACK_WRITEMASK                GL_STENCIL_BACK_WRITEMASK
#define STENCIL_BITS                          GL_STENCIL_BITS
#define STENCIL_BUFFER_BIT                    GL_STENCIL_BUFFER_BIT
#define STENCIL_CLEAR_VALUE                   GL_STENCIL_CLEAR_VALUE
#define STENCIL_FAIL                          GL_STENCIL_FAIL
#define STENCIL_FUNC                          GL_STENCIL_FUNC
#define STENCIL_INDEX                         GL_STENCIL_INDEX
#define STENCIL_PASS_DEPTH_FAIL               GL_STENCIL_PASS_DEPTH_FAIL
#define STENCIL_PASS_DEPTH_PASS               GL_STENCIL_PASS_DEPTH_PASS
#define STENCIL_REF                           GL_STENCIL_REF
#define STENCIL_TEST                          GL_STENCIL_TEST
#define STENCIL_VALUE_MASK                    GL_STENCIL_VALUE_MASK
#define STENCIL_WRITEMASK                     GL_STENCIL_WRITEMASK
#define STEREO                                GL_STEREO
#define STREAM_COPY                           GL_STREAM_COPY
#define STREAM_DRAW                           GL_STREAM_DRAW
#define STREAM_READ                           GL_STREAM_READ
#define SUBPIXEL_BITS                         GL_SUBPIXEL_BITS
#define T2F_C3F_V3F                           GL_T2F_C3F_V3F
#define T2F_C4F_N3F_V3F                       GL_T2F_C4F_N3F_V3F
#define T2F_C4UB_V3F                          GL_T2F_C4UB_V3F
#define T2F_N3F_V3F                           GL_T2F_N3F_V3F
#define T2F_V3F                               GL_T2F_V3F
#define T4F_C4F_N3F_V4F                       GL_T4F_C4F_N3F_V4F
#define T4F_V4F                               GL_T4F_V4F
#define TEXTURE                               GL_TEXTURE
#define TEXTURE0                              GL_TEXTURE0
#define TEXTURE1                              GL_TEXTURE1
#define TEXTURE2                              GL_TEXTURE2
#define TEXTURE3                              GL_TEXTURE3
#define TEXTURE4                              GL_TEXTURE4
#define TEXTURE5                              GL_TEXTURE5
#define TEXTURE6                              GL_TEXTURE6
#define TEXTURE7                              GL_TEXTURE7
#define TEXTURE8                              GL_TEXTURE8
#define TEXTURE9                              GL_TEXTURE9
#define TEXTURE10                             GL_TEXTURE10
#define TEXTURE11                             GL_TEXTURE11
#define TEXTURE12                             GL_TEXTURE12
#define TEXTURE13                             GL_TEXTURE13
#define TEXTURE14                             GL_TEXTURE14
#define TEXTURE15                             GL_TEXTURE15
#define TEXTURE16                             GL_TEXTURE16
#define TEXTURE17                             GL_TEXTURE17
#define TEXTURE18                             GL_TEXTURE18
#define TEXTURE19                             GL_TEXTURE19
#define TEXTURE20                             GL_TEXTURE20
#define TEXTURE21                             GL_TEXTURE21
#define TEXTURE22                             GL_TEXTURE22
#define TEXTURE23                             GL_TEXTURE23
#define TEXTURE24                             GL_TEXTURE24
#define TEXTURE25                             GL_TEXTURE25
#define TEXTURE26                             GL_TEXTURE26
#define TEXTURE27                             GL_TEXTURE27
#define TEXTURE28                             GL_TEXTURE28
#define TEXTURE29                             GL_TEXTURE29
#define TEXTURE30                             GL_TEXTURE30
#define TEXTURE31                             GL_TEXTURE31
#define TEXTURE0_ARB                          GL_TEXTURE0_ARB
#define TEXTURE1_ARB                          GL_TEXTURE1_ARB
#define TEXTURE2_ARB                          GL_TEXTURE2_ARB
#define TEXTURE3_ARB                          GL_TEXTURE3_ARB
#define TEXTURE4_ARB                          GL_TEXTURE4_ARB
#define TEXTURE5_ARB                          GL_TEXTURE5_ARB
#define TEXTURE6_ARB                          GL_TEXTURE6_ARB
#define TEXTURE7_ARB                          GL_TEXTURE7_ARB
#define TEXTURE8_ARB                          GL_TEXTURE8_ARB
#define TEXTURE9_ARB                          GL_TEXTURE9_ARB
#define TEXTURE10_ARB                         GL_TEXTURE10_ARB
#define TEXTURE11_ARB                         GL_TEXTURE11_ARB
#define TEXTURE12_ARB                         GL_TEXTURE12_ARB
#define TEXTURE13_ARB                         GL_TEXTURE13_ARB
#define TEXTURE14_ARB                         GL_TEXTURE14_ARB
#define TEXTURE15_ARB                         GL_TEXTURE15_ARB
#define TEXTURE16_ARB                         GL_TEXTURE16_ARB
#define TEXTURE17_ARB                         GL_TEXTURE17_ARB
#define TEXTURE18_ARB                         GL_TEXTURE18_ARB
#define TEXTURE19_ARB                         GL_TEXTURE19_ARB
#define TEXTURE20_ARB                         GL_TEXTURE20_ARB
#define TEXTURE21_ARB                         GL_TEXTURE21_ARB
#define TEXTURE22_ARB                         GL_TEXTURE22_ARB
#define TEXTURE23_ARB                         GL_TEXTURE23_ARB
#define TEXTURE24_ARB                         GL_TEXTURE24_ARB
#define TEXTURE25_ARB                         GL_TEXTURE25_ARB
#define TEXTURE26_ARB                         GL_TEXTURE26_ARB
#define TEXTURE27_ARB                         GL_TEXTURE27_ARB
#define TEXTURE28_ARB                         GL_TEXTURE28_ARB
#define TEXTURE29_ARB                         GL_TEXTURE29_ARB
#define TEXTURE30_ARB                         GL_TEXTURE30_ARB
#define TEXTURE31_ARB                         GL_TEXTURE31_ARB
#define TEXTURE_1D                            GL_TEXTURE_1D
#define TEXTURE_2D                            GL_TEXTURE_2D
#define TEXTURE_ALPHA_SIZE                    GL_TEXTURE_ALPHA_SIZE
#define TEXTURE_BINDING_1D                    GL_TEXTURE_BINDING_1D
#define TEXTURE_BINDING_2D                    GL_TEXTURE_BINDING_2D
#define TEXTURE_BINDING_CUBE_MAP              GL_TEXTURE_BINDING_CUBE_MAP
#define TEXTURE_BIT                           GL_TEXTURE_BIT
#define TEXTURE_BLUE_SIZE                     GL_TEXTURE_BLUE_SIZE
#define TEXTURE_BORDER                        GL_TEXTURE_BORDER
#define TEXTURE_BORDER_COLOR                  GL_TEXTURE_BORDER_COLOR
#define TEXTURE_COMPONENTS                    GL_TEXTURE_COMPONENTS
#define TEXTURE_COMPRESSED                    GL_TEXTURE_COMPRESSED
#define TEXTURE_COMPRESSED_IMAGE_SIZE         GL_TEXTURE_COMPRESSED_IMAGE_SIZE
#define TEXTURE_COMPRESSION_HINT              GL_TEXTURE_COMPRESSION_HINT
#define TEXTURE_COORD_ARRAY                   GL_TEXTURE_COORD_ARRAY
#define TEXTURE_COORD_ARRAY_BUFFER_BINDING    GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING
#define TEXTURE_COORD_ARRAY_POINTER           GL_TEXTURE_COORD_ARRAY_POINTER
#define TEXTURE_COORD_ARRAY_SIZE              GL_TEXTURE_COORD_ARRAY_SIZE
#define TEXTURE_COORD_ARRAY_STRIDE            GL_TEXTURE_COORD_ARRAY_STRIDE
#define TEXTURE_COORD_ARRAY_TYPE              GL_TEXTURE_COORD_ARRAY_TYPE
#define TEXTURE_CUBE_MAP                      GL_TEXTURE_CUBE_MAP
#define TEXTURE_CUBE_MAP_NEGATIVE_X           GL_TEXTURE_CUBE_MAP_NEGATIVE_X
#define TEXTURE_CUBE_MAP_NEGATIVE_Y           GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
#define TEXTURE_CUBE_MAP_NEGATIVE_Z           GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
#define TEXTURE_CUBE_MAP_POSITIVE_X           GL_TEXTURE_CUBE_MAP_POSITIVE_X
#define TEXTURE_CUBE_MAP_POSITIVE_Y           GL_TEXTURE_CUBE_MAP_POSITIVE_Y
#define TEXTURE_CUBE_MAP_POSITIVE_Z           GL_TEXTURE_CUBE_MAP_POSITIVE_Z
#define TEXTURE_ENV                           GL_TEXTURE_ENV
#define TEXTURE_ENV_COLOR                     GL_TEXTURE_ENV_COLOR
#define TEXTURE_ENV_MODE                      GL_TEXTURE_ENV_MODE
#define TEXTURE_GEN_MODE                      GL_TEXTURE_GEN_MODE
#define TEXTURE_GEN_Q                         GL_TEXTURE_GEN_Q
#define TEXTURE_GEN_R                         GL_TEXTURE_GEN_R
#define TEXTURE_GEN_S                         GL_TEXTURE_GEN_S
#define TEXTURE_GEN_T                         GL_TEXTURE_GEN_T
#define TEXTURE_GREEN_SIZE                    GL_TEXTURE_GREEN_SIZE
#define TEXTURE_HEIGHT                        GL_TEXTURE_HEIGHT
#define TEXTURE_INTENSITY_SIZE                GL_TEXTURE_INTENSITY_SIZE
#define TEXTURE_INTERNAL_FORMAT               GL_TEXTURE_INTERNAL_FORMAT
#define TEXTURE_LUMINANCE_SIZE                GL_TEXTURE_LUMINANCE_SIZE
#define TEXTURE_MAG_FILTER                    GL_TEXTURE_MAG_FILTER
#define TEXTURE_MATRIX                        GL_TEXTURE_MATRIX
#define TEXTURE_MIN_FILTER                    GL_TEXTURE_MIN_FILTER
#define TEXTURE_PRIORITY                      GL_TEXTURE_PRIORITY
#define TEXTURE_RED_SIZE                      GL_TEXTURE_RED_SIZE
#define TEXTURE_RESIDENT                      GL_TEXTURE_RESIDENT
#define TEXTURE_STACK_DEPTH                   GL_TEXTURE_STACK_DEPTH
#define TEXTURE_WIDTH                         GL_TEXTURE_WIDTH
#define TEXTURE_WRAP_S                        GL_TEXTURE_WRAP_S
#define TEXTURE_WRAP_T                        GL_TEXTURE_WRAP_T
#define TRANSFORM_BIT                         GL_TRANSFORM_BIT
#define TRIANGLES                             GL_TRIANGLES
#define TRIANGLE_FAN                          GL_TRIANGLE_FAN
#define TRIANGLE_STRIP                        GL_TRIANGLE_STRIP
#define UNPACK_ALIGNMENT                      GL_UNPACK_ALIGNMENT
#define UNPACK_LSB_FIRST                      GL_UNPACK_LSB_FIRST
#define UNPACK_ROW_LENGTH                     GL_UNPACK_ROW_LENGTH
#define UNPACK_SKIP_PIXELS                    GL_UNPACK_SKIP_PIXELS
#define UNPACK_SKIP_ROWS                      GL_UNPACK_SKIP_ROWS
#define UNPACK_SWAP_BYTES                     GL_UNPACK_SWAP_BYTES
#define UNSIGNED_BYTE                         GL_UNSIGNED_BYTE
#define UNSIGNED_INT                          GL_UNSIGNED_INT
#define UNSIGNED_SHORT                        GL_UNSIGNED_SHORT
#define UNSIGNED_SHORT_5_6_5                  GL_UNSIGNED_SHORT_5_6_5
#define UPPER_LEFT                            GL_UPPER_LEFT
#define V2F                                   GL_V2F
#define V3F                                   GL_V3F
#define VALIDATE_STATUS                       GL_VALIDATE_STATUS
#define VENDOR                                GL_VENDOR
#define VERSION                               GL_VERSION
#define VERTEX_ARRAY                          GL_VERTEX_ARRAY
#define VERTEX_ARRAY_BINDING                  GL_VERTEX_ARRAY_BINDING
#define VERTEX_ARRAY_BUFFER_BINDING           GL_VERTEX_ARRAY_BUFFER_BINDING
#define VERTEX_ARRAY_POINTER                  GL_VERTEX_ARRAY_POINTER
#define VERTEX_ARRAY_SIZE                     GL_VERTEX_ARRAY_SIZE
#define VERTEX_ARRAY_STRIDE                   GL_VERTEX_ARRAY_STRIDE
#define VERTEX_ARRAY_TYPE                     GL_VERTEX_ARRAY_TYPE
#define VERTEX_ATTRIB_ARRAY_BUFFER_BINDING    GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING
#define VERTEX_ATTRIB_ARRAY_ENABLED           GL_VERTEX_ATTRIB_ARRAY_ENABLED
#define VERTEX_ATTRIB_ARRAY_NORMALIZED        GL_VERTEX_ATTRIB_ARRAY_NORMALIZED
#define VERTEX_ATTRIB_ARRAY_POINTER           GL_VERTEX_ATTRIB_ARRAY_POINTER
#define VERTEX_ATTRIB_ARRAY_SIZE              GL_VERTEX_ATTRIB_ARRAY_SIZE
#define VERTEX_ATTRIB_ARRAY_STRIDE            GL_VERTEX_ATTRIB_ARRAY_STRIDE
#define VERTEX_ATTRIB_ARRAY_TYPE              GL_VERTEX_ATTRIB_ARRAY_TYPE
#define VERTEX_PROGRAM_POINT_SIZE             GL_VERTEX_PROGRAM_POINT_SIZE
#define VERTEX_PROGRAM_TWO_SIDE               GL_VERTEX_PROGRAM_TWO_SIDE
#define VERTEX_SHADER                         GL_VERTEX_SHADER
#define VERTEX_SHADER_ARB                     GL_VERTEX_SHADER_ARB
#define VIEWPORT                              GL_VIEWPORT
#define VIEWPORT_BIT                          GL_VIEWPORT_BIT
#define WEIGHT_ARRAY_BUFFER_BINDING           GL_WEIGHT_ARRAY_BUFFER_BINDING
#define WRITE_ONLY                            GL_WRITE_ONLY
#define XOR                                   GL_XOR
#define ZERO                                  GL_ZERO
#define ZOOM_X                                GL_ZOOM_X
#define ZOOM_Y                                GL_ZOOM_Y
#define COLOR_SUM                             GL_COLOR_SUM
#define COLOR_TABLE                           GL_COLOR_TABLE
#define CONVOLUTION_1D                        GL_CONVOLUTION_1D
#define CONVOLUTION_2D                        GL_CONVOLUTION_2D
#define HISTOGRAM                             GL_HISTOGRAM
#define MINMAX                                GL_MINMAX
#define POST_COLOR_MATRIX_COLOR_TABLE         GL_POST_COLOR_MATRIX_COLOR_TABLE
#define POST_CONVOLUTION_COLOR_TABLE          GL_POST_CONVOLUTION_COLOR_TABLE
#define RESCALE_NORMAL                        GL_RESCALE_NORMAL
#define SEPARABLE_2D                          GL_SEPARABLE_2D
#define TEXTURE_3D                            GL_TEXTURE_3D
#define CONSTANT_COLOR                        GL_CONSTANT_COLOR
#define ONE_MINUS_CONSTANT_COLOR              GL_ONE_MINUS_CONSTANT_COLOR
#define CONSTANT_ALPHA                        GL_CONSTANT_ALPHA
#define ONE_MINUS_CONSTANT_ALPHA              GL_ONE_MINUS_CONSTANT_ALPHA

// undef
#undef BF_FLAT

// opaque blend modes
#define BF_ADD_FLAT  0x11
#define BF_FLAT      0x10
#define BF_SUB_FLAT  0x02

// transparent blend modes
#define BF_ADD       0x61
#define BF_ALPHA     0x67
#define BF_SUB       0x47

// inversed transparent blend modes
#define BF_INV_ADD   0x71
#define BF_INV_ALPHA 0x76
#define BF_INV_SUB   0x46

/* opengl handling subsystem function macro implementations */

// simple toggle macro definitions
#define INL_GL_DISENABLE(AA,BB)\
inline bl AA(){return is_enabled(GL_##BB);};\
inline void AA(bl a){enable(GL_##BB,a);}

// complex toggle macro definitions
#define INL_GL_DISENABLE_I(AA,BB)\
inline bl AA(s32 a){return is_enabled(GL_##BB + a);};\
inline void AA(s32 a,bl b){enable(GL_##BB + a,b);}

// hint macro definition
#define INL_GL_HINT(AA,BB)\
inline void AA##_hint(GLenum a){glHint(GL_##BB,a);}

// matrix mode macro definition
#define INL_GL_MATRIX(AA,BB)\
inline void AA##_matrix(){matrix_mode(GL_##BB);};\
inline void AA##_matrix(const f32* m){matrix_mode(GL_##BB);matrix(m);};\
inline void AA##_matrix(const math::mat4& m){matrix_mode(GL_##BB);matrix(m);}

// simple toggle macro implementations

INL_GL_DISENABLE( alpha_test,                   ALPHA_TEST                    );
INL_GL_DISENABLE( auto_normal,                  AUTO_NORMAL                   );
INL_GL_DISENABLE( blend,                        BLEND                         );
INL_GL_DISENABLE( color_logic_op,               COLOR_LOGIC_OP                );
INL_GL_DISENABLE( color_material,               COLOR_MATERIAL                );
INL_GL_DISENABLE( color_sum,                    COLOR_SUM                     );
INL_GL_DISENABLE( color_table,                  COLOR_TABLE                   );
INL_GL_DISENABLE( convolution_1d,               CONVOLUTION_1D                );
INL_GL_DISENABLE( convolution_2d,               CONVOLUTION_2D                );
INL_GL_DISENABLE( cull_face,                    CULL_FACE                     );
INL_GL_DISENABLE( depth_test,                   DEPTH_TEST                    );
INL_GL_DISENABLE( dither,                       DITHER                        );
INL_GL_DISENABLE( fog,                          FOG                           );
INL_GL_DISENABLE( histogram,                    HISTOGRAM                     );
INL_GL_DISENABLE( index_logic_op,               INDEX_LOGIC_OP                );
INL_GL_DISENABLE( line_smooth,                  LINE_SMOOTH                   );
INL_GL_DISENABLE( line_stipple,                 LINE_STIPPLE                  );
INL_GL_DISENABLE( lighting,                     LIGHTING                      );
INL_GL_DISENABLE( minmax,                       MINMAX                        );
INL_GL_DISENABLE( multisample,                  MULTISAMPLE                   );
INL_GL_DISENABLE( normalize,                    NORMALIZE                     );
INL_GL_DISENABLE( point_smooth,                 POINT_SMOOTH                  );
INL_GL_DISENABLE( point_sprite,                 POINT_SPRITE                  );
INL_GL_DISENABLE( polygon_offset_fill,          POLYGON_OFFSET_FILL           );
INL_GL_DISENABLE( polygon_offset_line,          POLYGON_OFFSET_LINE           );
INL_GL_DISENABLE( polygon_offset_point,         POLYGON_OFFSET_POINT          );
INL_GL_DISENABLE( polygon_smooth,               POLYGON_SMOOTH                );
INL_GL_DISENABLE( polygon_stipple,              POLYGON_STIPPLE               );
INL_GL_DISENABLE( post_color_matrix_color_table,POST_COLOR_MATRIX_COLOR_TABLE );
INL_GL_DISENABLE( post_convolution_color_table, POST_CONVOLUTION_COLOR_TABLE  );
INL_GL_DISENABLE( rescale_normal,               RESCALE_NORMAL                );
INL_GL_DISENABLE( sample_alpha_to_coverage,     SAMPLE_ALPHA_TO_COVERAGE      );
INL_GL_DISENABLE( sample_alpha_to_one,          SAMPLE_ALPHA_TO_ONE           );
INL_GL_DISENABLE( sample_coverage,              SAMPLE_COVERAGE               );
INL_GL_DISENABLE( separable_2d,                 SEPARABLE_2D                  );
INL_GL_DISENABLE( scissor_test,                 SCISSOR_TEST                  );
INL_GL_DISENABLE( stencil_test,                 STENCIL_TEST                  );
INL_GL_DISENABLE( texture_1d,                   TEXTURE_1D                    );
INL_GL_DISENABLE( texture_2d,                   TEXTURE_2D                    );
INL_GL_DISENABLE( texture_3d,                   TEXTURE_3D                    );
INL_GL_DISENABLE( texture_cube_map,             TEXTURE_CUBE_MAP              );
INL_GL_DISENABLE( texture_gen_q,                TEXTURE_GEN_Q                 );
INL_GL_DISENABLE( texture_gen_r,                TEXTURE_GEN_R                 );
INL_GL_DISENABLE( texture_gen_s,                TEXTURE_GEN_S                 );
INL_GL_DISENABLE( texture_gen_t,                TEXTURE_GEN_T                 );
INL_GL_DISENABLE( vertex_program_point_size,    VERTEX_PROGRAM_POINT_SIZE     );
INL_GL_DISENABLE( vertex_program_two_side,      VERTEX_PROGRAM_TWO_SIDE       );

// complex toggle macro implementations

INL_GL_DISENABLE_I( clip_plane, CLIP_PLANE0 );
INL_GL_DISENABLE_I( light,      LIGHT0      );

// hint macro implementation

INL_GL_HINT( fog,         FOG_HINT                        );
INL_GL_HINT( line,        LINE_SMOOTH_HINT                );
INL_GL_HINT( mipmap,      GENERATE_MIPMAP_HINT            );
INL_GL_HINT( perspective, PERSPECTIVE_CORRECTION_HINT     );
INL_GL_HINT( point,       POINT_SMOOTH_HINT               );
INL_GL_HINT( polygon,     POLYGON_SMOOTH_HINT             );
INL_GL_HINT( texture,     TEXTURE_COMPRESSION_HINT        );
INL_GL_HINT( shader,      FRAGMENT_SHADER_DERIVATIVE_HINT );

// matrix mode macro implementation

INL_GL_MATRIX( model,      MODELVIEW  );
INL_GL_MATRIX( projection, PROJECTION );
INL_GL_MATRIX( texture,    TEXTURE    );
INL_GL_MATRIX( color,      COLOR      );

/* end */

}
}

#endif
