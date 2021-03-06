#ifndef HSCPOINTS_H
#define HSCPOINTS_H

#include <inttypes.h>
#include <string>
#include <deque>
#include <functional>
#include "hsc_include.h"

#define POINTS_FIRST_IDX 2

class HSCPoint;
class HSCPointParam;

class HSCPoints
{
public:
    HSCPoints();

    static bool init(bool from_file = false);
    static bool check_point_index(int32_t point);
    static int32_t get_count() { return m_inst->m_points_indexes[POINTS_FIRST_IDX]; }
    static int32_t get_idx(int32_t point) { return m_inst->m_points_indexes[POINTS_FIRST_IDX + point]; }
    static void set_idx(int32_t point, int32_t val) { m_inst->m_points_indexes[POINTS_FIRST_IDX + point] = val; }

    static int scan_all_points();

    static void hist_queue_clear() { m_inst->m_params.clear(); }
    static void hist_queue_add(HSCPointParam *param);
    static bool hist_update(std::function<void(HSCPointParam*)> on_param_value);

    static HSCPoint* get_point(int32_t number);
    static HSCPoint* get_point(std::string name);

    static int get_points_count() { return m_inst->m_points.size(); }
    static HSCPoint* get_point_by_idx(int32_t idx) { if (idx < m_inst->m_points.size()) return m_inst->m_points[idx]; else return nullptr; }
private:
    void                        *m_addr;
    int32_t                     *m_points_indexes;
    std::deque<HSCPoint*>       m_points;
    std::deque<HSCPointParam*>  m_params;
    PARvalue                    *m_values;

    static HSCPoints *m_inst;
};

#endif // HSCPOINTS_H
