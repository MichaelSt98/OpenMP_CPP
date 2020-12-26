//
// Created by Michael Staneker on 26.12.20.
//

#include "../include/RuntimeLibraryRoutines.h"

void monitor_influence_threads_routines() {

    //set number of threads
    omp_set_num_threads(4); //int nthreads);

    //Enables or disables dynamic adjustment of the number of threads
    // used to execute a parallel region. If dynamic_threads is TRUE,
    // dynamic threads are enabled. If dynamic_threads is FALSE, dynamic threads
    // are disabled. Dynamic threads are disabled by default.
    omp_set_dynamic(0); //int dynamic_threads);

    //Enables or disables nested parallelism. If nested is TRUE,
    // nested parallelism is enabled. If nested is FALSE, nested parallelism
    // is disabled. Nested parallelism is disabled by default.
    omp_set_nested(0); //int nested)

    //Returns the number of threads that are being used in the
    // current parallel region.
    int number_of_threads = omp_get_num_threads();

    //Returns the number of threads available to subsequent
    // parallel regions created by the calling thread.
    int max_number_of_threads = omp_get_max_threads();

    //Returns the thread number of the calling thread, within
    // the context of the current parallel region.
    int thread_number_of_current_thread = omp_get_thread_num();

    //Returns the number of processors available to the program.
    int number_of_available_processors = omp_get_num_procs();

    //Returns TRUE if called within the dynamic extent of a parallel
    // region executing in parallel; otherwise returns FALSE.
    int within_parallel = omp_in_parallel();

    //Returns TRUE if called within a final task region;
    // otherwise returns FALSE.
    int within_final = omp_in_final();

    //Returns TRUE if dynamic thread adjustment is enabled,
    // otherwise returns FALSE.
    int within_dynamic = omp_get_dynamic();

    //Returns TRUE if nested parallelism is enabled,
    // otherwise returns FALSE.
    int within_nested =  omp_get_nested();

    // Returns the maximum number of simultaneously
    // executing threads in an OpenMP program.
    int thread_limit = omp_get_thread_limit();

    //Limits the number of nested active parallel regions. The call is
    // ignored if negative max_active_levels specified.
    //omp_set_max_active_levels(int max_active_levels)

    //Returns the maximum number of nested active parallel regions.
    int maximum_levels = omp_get_max_active_levels();

    //Returns the number of nested parallel regions (whether active or inactive)
    // enclosing the task that contains the call, not including the implicit
    // parallel region.
    int current_level = omp_get_level();

    //Returns the number of nested, active parallel regions enclosing
    // the task that contains the call.
    int current_active_level = omp_get_active_level();

    //Returns the thread number of the ancestor at a given nest
    // level of the current thread.
    //int omp_get_ancestor_thread_num(int level)

    //Returns the size of the thread team to which the ancestor of
    // the given level belongs.
    //int omp_get_team_size(int level);

    //Determines the schedule of a worksharing loop that is applied when 'runtime'
    // is used as the schedule kind.
    //void omp_set_schedule(omp_sched_t kind,int chunk_size);
    //void omp_get_schedule(omp_sched_kind *kind,int *chunk_size);

    //Returns the currently active thread affinity policy, which is set
    // by environment variable OMP_PROC_BIND.
    //omp_proc_bind_t omp_get_proc_bind(void);

    //Returns the number of places available to the execution environment
    // in the place list of the initial task, usually threads, cores, or sockets.
    //int omp_get_num_places(void);

    //Returns the number of processors associated with the place numbered place_num.
    // The routine returns zero when place_num is negative or is greater than or equal
    // to omp_get_num_places().
    //int omp_get_place_num_procs(int place_num);

    //Returns the numerical identifiers of each processor associated with the place numbered place_num.
    // The numerical identifiers are non-negative and their meaning is implementation defined. The
    // numerical identifiers are returned in the array ids and their order in the array is implementation
    // defined. ids must have at least omp_get_place_num_procs(place_num) elements. The routine has no
    // effect when place_num is greater than or equal to omp_get_num_places().
    //void omp_get_place_proc_ids(int place_num, int *ids)

    //Returns the place number of the place to which the encountering thread is bound. The returned
    // value is between 0 and omp_get_num_places() - 1, inclusive. When the encountering thread is
    // not bound to a place, the routine returns -1.
    //int omp_get_place_num(void)

    //Returns the default device number.
    int default_device_number = omp_get_default_device();

    //Sets the default device number.
    omp_set_default_device(default_device_number); // int device_number);

    //Gets the number of target devices.
    int number_of_target_devices = omp_get_num_devices();

    //Gets the number of teams in the current teams region.
    int number_of_teams_in_region = omp_get_num_teams();

    //Gets the team number of the calling thread.
    int team_number_current_thread = omp_get_team_num();

    //Returns TRUE if cancellation is enabled; otherwise, FALSE.
    int cancellation = omp_get_cancellation();

    //Returns TRUE if the current task is running on the host device;
    // otherwise, FALSE.
    int on_host_device = omp_is_initial_device();

    //Returns the device number of the host device. The value of the device number
    // is implementation defined. If it is between 0 and omp_get_num_devices()-1, then it
    // is valid in all device constructs and routines; if it is outside that range, then it is
    // only valid in the device memory routines and not in the device clause.
    int device_number_of_host_device = omp_get_initial_device();

    //Returns the maximum value that can be specified in the priority clause.
    int max_task_priority = omp_get_max_task_priority();

    //Returns a storage location's device address, where the size of the
    // location is measured in bytes.
    //void * omp_target_alloc(size_t size, int device_num)

    //Frees device memory that was allocated by the omp_target_alloc.
    //void omp_target_free(void *device_ptr, int device_num)

    //Returns TRUE if the specified pointer is found on the device specified by
    // device_num by a map clause. Otherwise, it returns FALSE.
    //int omp_target_is_present(void *ptr, int device_num)

    //This routine copies length bytes of memory at offset src_offset from src in the device data
    // environment of device
    // src_device_num to dst, starting at offset dst_offset in the device data environment of
    // the device specified by dst_device_num. Returns zero on success and a non-zero value on failure.
    // Use omp_get_initial_device to return a the device number you can use to reference the host device
    // and host device data environment. This routine includes a task scheduling point.
    //int omp_target_memcpy(void *dst, void *src, size_t length, size_t dst_offset, size_t src_offset, int dst_device, int src_device)

    //This routine copies a rectangular subvolume of src, in the device data environment of
    // the device specified by src_device_num, to dst, in the device data environment of the
    // device specified by dst_device_num. Specify the volume in terms of the size of an element,
    // the number of its dimensions, and constant arrays of length num_dims. The maximum number
    // of dimensions supported is three or more. The volume array specifies the length, in number
    // of elements, to copy in each dimension from src to dst. The dst_offsets and src_offsets
    // parameters specify the number of elements from the origin of dst and src, in elements.
    // The dst_dimensions and src_dimensions parameters specify the length of each dimension of
    // dst and src. The routine returns zero if successful. If both dst and src are NULL pointers,
    // the routine returns the number of dimensions supported by the implementation for the specified
    // device numbers. You can use the device number returned by omp_get_initial_device to reference
    // the host device and host device data environment. Otherwise, it returns a non-zero value. This
    // routine contains a task scheduling point.
    //int omp_target_memcpy_rect( void *dst, void *src,size_t element_size,int num_dims,const size_t *volume, const size_t *dst_offsets,const size_t *src_offsets, const size_t *dst_dimensions, const size_t *src_dimensions,int dst_device_num, int src_device_num)

    //Maps a device pointer, which might be returned by omp_target_alloc, to a host pointer.
    //int omp_target_associate_ptr(void *host_ptr, void *device_ptr, size_t size, size_t device_offset, int device_num)

}

void lock_routines() {

    //Initializes the lock associated with the simple lock
    // variable svar for use in subsequent calls.
    //void omp_init_lock(omp_lock_t svar)

    //Initializes the lock associated with svar to the unlocked state, optionally
    // choosing a specific lock implementation based on hint.
    //void omp_init_lock_with_hint(omp_lock_t *svar, omp_lock_hint_t hint)

    //Causes the lock specified by svar to become undefined or uninitialized.
    //void omp_destroy_lock(omp_lock_t svar)

    //Forces the executing thread to wait until the lock associated with svar is available.
    // The thread is granted ownership of the lock when it becomes available.
    //void omp_set_lock(omp_lock_t svar)

    //Releases the executing thread from ownership of the lock associated with svar.
    // The behavior is undefined if the executing thread does not own the lock
    // associated with svar.
    //void omp_unset_lock(omp_lock_t svar)

    //Attempts to set the lock associated with svar. If successful,
    // returns TRUE, otherwise returns FALSE.
    //int omp_test_lock(omp_lock_t svar)

    //Initializes the nested lock associated with the nested lock
    // variable nvar for use in the subsequent calls.
    //void omp_init_nest_lock(omp_nest_lock_t nvar)

    //Initializes the nested lock associated with nvar to the unlocked state,
    // optionally choosing a specific lock implementation based on hint.
    // The nesting count for nvar is set to zero.
    //void omp_init_lock_with_hint(omp_lock_t *nvar, omp_lock_hint_t hint);
    //void omp_init_nest_lock_with_hint(omp_nest_lock_t *nvar, omp_lock_hint_t hint);

    //Causes the nested lock associated with nvar to become
    // undefined or uninitialized.
    //void omp_destroy_nest_lock(omp_nest_lock_t nvar)

    //Forces the executing thread to wait until the nested lock associated with nvar is available.
    // If the thread already owns the lock, then the lock nesting count is incremented.
    //void omp_set_nest_lock(omp_nest_lock_t nvar)

    //Releases the executing thread from ownership of the nested lock associated with
    // nvar if the nesting count is zero; otherwise, the nesting count is decremented.
    // Behavior is undefined if the executing thread does not own the nested lock associated with nvar.
    //void omp_unset_nest_lock(omp_nest_lock_t lock)

    //Attempts to set the nested lock specified by nvar. If successful,
    // returns the nesting count, otherwise returns zero.
    //int omp_test_nest_lock(omp_nest_lock_t lock)

}

void timing_routines() {

    //Returns a double precision value equal to the elapsed wall clock time (in seconds)
    // relative to an arbitrary reference time. The reference time does not change during
    // program execution.
    double omp_time = omp_get_wtime();

    //Returns a double precision value equal to the number of seconds between successive
    // clock ticks.
    double omp_tick = omp_get_wtick();
}